#ifndef DELTATRON_FILESYSTEM_HEADER
#define DELTATRON_FILESYSTEM_HEADER

#include <dt/ProgramArgs.hpp>

#include <filesystem>
#include <string>

namespace dt {

namespace stdfs = std::filesystem;

class Filesystem final {
private:
  stdfs::path m_root_path;

public:
  Filesystem(ProgramArgs const& args);

  Filesystem(Filesystem const&) = delete;

  Filesystem(Filesystem&&) = delete;

  Filesystem& operator=(Filesystem const&) = delete;

  Filesystem& operator=(Filesystem&&) = delete;

  ~Filesystem() noexcept = default;

  constexpr stdfs::path const& root_path() const noexcept { return m_root_path; }
};

}

#endif // DELTATRON_FILESYSTEM_HEADER
