#include <dt/ProgramArgs.hpp>

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace dt::Private {

std::streamsize max_name_length(ProgramArgs::flag_list_type const& flag_list) noexcept {
  auto const& [type, flag] = *std::max_element(flag_list.begin(), flag_list.end(),
    [](auto&& big_pair, auto&& next_pair) {
      auto const& big_name  = big_pair.second.name();
      auto const& next_name = next_pair.second.name();

      return big_name.size() < next_name.size();
    }
  );

  // std::strlen("Name ") == 5
  return static_cast<std::streamsize>(flag.name().size() < 5 ? 5: flag.name().size() + 1);
}

std::streamsize max_alias_length(ProgramArgs::flag_list_type const& flag_list) noexcept {
  auto const& [type, flag] = *std::max_element(flag_list.begin(), flag_list.end(),
    [](auto&& big_pair, auto&& next_pair) {
      auto const& big_name  = big_pair.second.alias();
      auto const& next_name = next_pair.second.alias();

      return big_name.size() < next_name.size();
    }
  );

  // std::strlen("Alias ") == 6
  return static_cast<std::streamsize>(flag.alias().size() < 6 ? 6 : flag.alias().size() + 1);
}

}

std::string dt::ProgramArgs::help_menu() const {
  auto const name_width       = Private::max_name_length(m_flag_list);
  auto const alias_width      = Private::max_alias_length(m_flag_list);
  auto const definition_width = (name_width + alias_width) - static_cast<std::streamsize>(m_line_width);

  auto help_strm = std::stringstream{};

  help_strm << "Deltatron version " << DELTATRON_VERSION_STRING << std::endl;

  help_strm << std::left
    << std::setw(name_width) << "Name "
    << std::setw(alias_width) << "Alias "
    << std::setw(definition_width) << "Definition" << std::endl;

  for (auto const& [type, flag] : m_flag_list)
    help_strm << std::left
      << std::setw(name_width) << flag.name()
      << std::setw(alias_width) << flag.alias()
      << std::setw(definition_width) << flag.definition() << std::endl;

  return help_strm.str();
}
