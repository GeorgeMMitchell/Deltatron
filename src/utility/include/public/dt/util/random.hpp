#ifndef DELTATRON_UTILITY_RANDOM_HEADER
#define DELTATRON_UTILITY_RANDOM_HEADER

#include <cstddef>

namespace dt {

class random_t final {
public:
  using size_type = std::size_t;

private:
  size_type m_storage;

public:
  constexpr random_t(size_type const seed) noexcept
  : m_storage{1'492'017'283'940'593'731}
  { m_storage ^= seed; m_storage -= get(); }

  constexpr size_type get() noexcept {
    m_storage ^= m_storage >> 19;
    m_storage ^= m_storage << 29;
    m_storage ^= m_storage >> 7;
    m_storage ^= m_storage << 17;
    m_storage ^= m_storage >> 23;

    return m_storage *= 1'192'039'485'726'384'957;
  }
};

}

#endif // DELTATRON_UTILITY_RANDOM_HEADER
