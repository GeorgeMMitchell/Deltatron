#ifndef DELTATRON_UTILITY_BUFFER_HEADER
#define DELTATRON_UTILITY_BUFFER_HEADER

#include <cstddef>

namespace dt {

template <typename T, std::size_t N>
class buffer_type final {
public:
  using size_type     = std::size_t;
  using value_type    = T;
  using pointer       = T*;
  using const_pointer = T const*;

  static constexpr auto size = N;

  T array[N];

  constexpr auto cdata() const noexcept -> const_pointer { return &array[0]; }
  constexpr auto data()  const noexcept -> const_pointer { return &array[0]; }
  constexpr auto data()        noexcept -> pointer       { return &array[0]; }

  constexpr auto cbegin() const noexcept -> const_pointer { return data(); }
  constexpr auto begin()  const noexcept -> const_pointer { return data(); }
  constexpr auto begin()        noexcept -> pointer       { return data(); }

  constexpr auto cend() const noexcept -> const_pointer { return data() + size; }
  constexpr auto end()  const noexcept -> const_pointer { return data() + size; }
  constexpr auto end()        noexcept -> pointer       { return data() + size; }
};

}

#endif // DELTATRON_UTILITY_BUFFER_HEADER
