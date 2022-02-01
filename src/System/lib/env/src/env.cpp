#include <dt/env.hpp>

#include <dt/util/buffer.hpp>

#include <algorithm>
#include <array>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

#ifdef _WIN32
  #include <userenv.h>
#else
  #include <unistd.h>
#endif

namespace dt::env::Private {

#ifdef _WIN32

template <typename CharT>
std::optional<std::basic_string<CharT>> win32_getenv(std::basic_string<CharT> const& name) {
  auto entry_buffer = buffer_type<CharT, 1024>{};
  auto entry_size   = std::size_t{};
  auto getenv_err   = errno_t{};

  if constexpr (std::is_same_v<CharT, wchar_t>)
    getenv_err = _wgetenv_s<entry_buffer.size>(&entry_size, entry_buffer.array, name.c_str());

  else
    getenv_err = getenv_s<entry_buffer.size>(&entry_size, entry_buffer.array, name.c_str());

  if (getenv_err != 0 || entry_size == 0)
    return {};

  return std::basic_string<CharT>(entry_buffer.array, entry_size - 1);
}

#endif // _WIN32

} // namespace dt::env

std::optional<std::string> dt::env::entry_value(std::string const& name) {
#ifdef _WIN32
  return Private::win32_getenv<char>(name);

#else
  auto const value = getenv(name.c_str());

  if (value == nullptr)
    return {};

  return value;

#endif
}
