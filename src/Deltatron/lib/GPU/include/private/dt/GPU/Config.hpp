#ifndef DELTATRON_GPU_CONFIG_HEADER
#define DELTATRON_GPU_CONFIG_HEADER

namespace dt {

class GPUConfig final {
public:
  GPUConfig() = delete;

  GPUConfig(System const& system);

  GPUConfig(GPUConfig const&) = delete;

  GPUConfig(GPUConfig&&) = delete;

  ~GPUConfig() noexcept = default;

  GPUConfig& operator=(GPUConfig const&) = delete;

  GPUConfig& operator=(GPUConfig&&) = delete;
};

}

#endif // DELTATRON_GPU_CONFIG_HEADER
