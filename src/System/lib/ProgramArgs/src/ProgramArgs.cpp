#include <dt/ProgramArgs.hpp>

#include <cmake/cmake_info.h>

#include <algorithm>
#include <iostream>

namespace dt::Private {

ProgramArgs::arg_list_type create_arg_list(int const argc, ProgramArgs::argv_type const argv) {
  auto const argc_sz_t = static_cast<std::size_t>(argc);

  auto arg_list = ProgramArgs::arg_list_type(argc_sz_t);

  for (std::size_t idx{}; idx < argc_sz_t; ++idx)
    arg_list[idx] = argv[idx];

  return arg_list;
}

}

dt::ProgramArgs::ProgramArgs(int const argc, argv_type const argv)
: m_arg_list{Private::create_arg_list(argc, argv)}
{
  for (auto const& [_, f] : m_flag_list)
    check_flag_width(f);

  if (flag_passed(dt::flag_type::Help)) {
    std::cerr << help_menu();

    std::exit(EXIT_SUCCESS);
  }

  if (flag_passed(dt::flag_type::Version)) {
    std::cerr << DELTATRON_VERSION_STRING << std::endl;

    std::exit(EXIT_SUCCESS);
  }
}

dt::ProgramArgs::~ProgramArgs() noexcept {}

bool dt::ProgramArgs::flag_passed(flag_type const type) const noexcept {
  auto const& flaginfo = flag_info(type);

  for (auto const& arg : m_arg_list)
    if (arg == flaginfo.name() || arg == flaginfo.alias())
      return true;

  return false;
}

std::optional<std::string_view> dt::ProgramArgs::value(flag_type const type) const {
  auto arg_iter = std::find_if(m_arg_list.begin(), m_arg_list.end(),
    [&flaginfo = flag_info(type)] (auto&& arg)
    { return arg == flaginfo.name() || arg == flaginfo.alias(); });

  if (arg_iter == m_arg_list.end() || arg_iter + 1 == m_arg_list.end())
    return {};

  auto const& value = *(arg_iter + 1);

    for (auto const& fi : m_flag_info_list)
      if (fi->name() == value|| fi->alias() == value)
        return {};

  return value.data();
}

dt::ProgramArgs::flag_list_type dt::ProgramArgs::create_flag_list() const {
  return {
    { flag_type::Help, {
      "--help",
      "-h",
      "Displays flag definitions"
    } },

    { flag_type::Version, {
      "--version",
      "-v",
      "Displays program version"
    } },

    { flag_type::RootDir, {
      "--root-fs",
      "",
      "Manually specifies program's root filesystem directory"
    } }
  };
}

dt::ProgramArgs::flag_info_list_type dt::ProgramArgs::create_flag_info_list() const {
  auto flag_info_list = flag_info_list_type(m_flag_list.size());

  auto idx = std::size_t{};
  for (auto const& [_, f] : m_flag_list)
    flag_info_list[idx++] = std::addressof(f);

  return flag_info_list;
}

void dt::ProgramArgs::check_flag_width(flag const& f) const {
  if (m_line_width <= (f.name().size() + f.alias().size()))
    throw dt::exception{"flag exceeds line width"};
}


dt::ProgramArgs::flag const& dt::ProgramArgs::flag_info(flag_type const type) const
{ return m_flag_list.find(type)->second; }
