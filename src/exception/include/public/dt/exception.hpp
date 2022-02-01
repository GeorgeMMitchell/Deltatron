#ifndef DELTATRON_EXCEPTION_HEADER
#define DELTATRON_EXCEPTION_HEADER

#include <exception>
#include <string>

namespace dt {

class exception : public std::exception {
private:
  std::string m_what;

public:
  exception() = default;

  exception(std::string const& what);

  exception(exception const&) = default;

  exception(exception&&) noexcept = default;

  virtual ~exception() = default;

  exception& operator=(exception const&) = default;

  exception& operator=(exception&&) noexcept = default;

  char const* what() const noexcept override;
};

}

#endif // DELTATRON_EXCEPTION_HEADER
