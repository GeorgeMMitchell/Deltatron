#include <dt/Filesystem.hpp>

#include <dt/env.hpp>
#include <dt/exception.hpp>

#include <filesystem>

#include <iostream>

namespace stdfs = std::filesystem;

namespace dt::Private {

#ifdef _WIN32
stdfs::path win32_resolve_program_root_dir(ProgramArgs const&) {
  if (auto const o_local_str = env::entry_value("LOCALAPPDATA"); o_local_str) {
    auto const root_dir = stdfs::path{*o_local_str} / "Deltatron";

    if (stdfs::exists(root_dir) && !stdfs::is_directory(root_dir))
      throw dt::exception{root_dir.string() + " is not a directory"};

    stdfs::create_directories(root_dir);

    return root_dir;
  }

  return stdfs::current_path();
}

#else
stdfs::path gen_resolve_program_root_dir(ProgramArgs const& args) {
  if (auto const o_home = env::entry_value("HOME"); o_home) {
    auto const root_dir = (stdfs::path{*o_home} / ".config") / "deltatron";

    if (!stdfs::exists(root_dir))
      stdfs::create_directories(root_dir);

    else if (!stdfs::is_directory(root_dir))
      throw dt::exception{root_dir.string() + " is not a directory"};

    return root_dir
  }

  return stdfs::current_path();
}
#endif

stdfs::path resolve_program_root_dir(ProgramArgs const& args) {
  if (auto const o_man_root_str = args.value(flag_type::RootDir); o_man_root_str)
    return stdfs::create_directories(*o_man_root_str), o_man_root_str.value();

  else if (auto const o_env_root_str = env::entry_value("DELTATRON_ROOT"); o_env_root_str)
    return stdfs::create_directories(*o_env_root_str), o_env_root_str.value();

#ifdef _WIN32
  return win32_resolve_program_root_dir(args);

#else
  return gen_resolve_program_root_dir(args);

#endif
}

}

dt::Filesystem::Filesystem(ProgramArgs const& args)
: m_root_path{Private::resolve_program_root_dir(args)} {}
