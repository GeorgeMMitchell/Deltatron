#ifndef DELTATRON_GPU_HEADER
#define DELTATRON_GPU_HEADER

#include <dt/System.hpp>

#include <memory>

namespace dt {

class GPUImp;

class GPU final {
private:
  std::unique_ptr<GPUImp> const m_gpu;

public:
  GPU() = delete;

  GPU(System const& system);

  GPU(GPU const&) = delete;

  GPU(GPU&&) = delete;

  ~GPU() noexcept;

  GPU& operator=(GPU const&) = delete;

  GPU& operator=(GPU&&) = delete;
};

}

#endif // DELTATRON_GPU_HEADER
