#ifndef DELTATRON_GPU_IMP_HEADER
#define DELTATRON_GPU_IMP_HEADER

#include <dt/System.hpp>

namespace dt {

class GPUImp final {
public:
  GPUImp() = delete;

  GPUImp(System const&) {}

  GPUImp(GPUImp const&) = delete;

  GPUImp(GPUImp&&) = delete;

  ~GPUImp() noexcept = default;

  GPUImp& operator=(GPUImp const&) = delete;

  GPUImp& operator=(GPUImp&&) = delete;
};

}

#endif // DELTATRON_GPU_IMP_HEADER
