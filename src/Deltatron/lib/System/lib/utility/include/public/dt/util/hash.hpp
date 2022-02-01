#ifndef DELTATRON_UTILITY_HASH_HEADER
#define DELTATRON_UTILITY_HASH_HEADER

#include <cstddef>

#include <cstring>

namespace dt {

// Daniel J. Bernstein's hash function
constexpr std::size_t hash_djb2(char const* const cstr) noexcept {
  auto data = reinterpret_cast<unsigned char const*>(cstr);
  auto key  = std::size_t{5381};

  for (int c{}; c = *data; ++data)
    key = ((key << 5) + key) + c; // == hash * 33 + c

  return key;
}

}

#endif // DELTATRON_UTILITY_HASH_HEADER
