#ifndef DELTATRON_ARGS_HEADER
#define DELTATRON_ARGS_HEADER

#include <dt/exception.hpp>

#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

#include <build/info.h>

#include <cstddef>

namespace dt {

enum class flag_type {
  Unknown, Help, Version, RootDir
};

class ProgramArgs final {
public:
  class flag final {
  public:
    enum class value_type { None, Single, Multi };

  private:
    std::string m_name;
    std::string m_alias;
    std::string m_definition;
    value_type  m_value;

  public:
    flag(
      std::string const& name,
      std::string const& alias,
      std::string const& definition,
      value_type  const  value = value_type::None
    );

    flag(flag const&) = default;

    flag(flag&&) noexcept = default;

    ~flag() noexcept = default;

    flag& operator=(flag const&) = default;

    flag& operator=(flag&&) noexcept = default;

    constexpr auto name()       const noexcept -> std::string const& { return m_name;       }
    constexpr auto alias()      const noexcept -> std::string const& { return m_alias;      }
    constexpr auto definition() const noexcept -> std::string const& { return m_definition; }
    constexpr auto value()      const noexcept -> value_type         { return m_value;      }
  };

  using argv_type           = char const* const*;
  using arg_list_type       = std::vector<std::string>;
  using flag_list_type      = std::unordered_map<flag_type, flag>;
  using flag_info_list_type = std::vector<flag const*>;

private:
  std::size_t         const m_line_width = 79;
  flag_list_type      const m_flag_list  = create_flag_list();
  flag_info_list_type const m_flag_info_list = create_flag_info_list();
  arg_list_type       const m_arg_list;

public:
  ProgramArgs(int const argc, argv_type const argv);

  ProgramArgs(ProgramArgs const&) = delete;

  ProgramArgs(ProgramArgs&&) = delete;

  ~ProgramArgs() noexcept;

  ProgramArgs& operator=(ProgramArgs const&) = delete;

  ProgramArgs& operator=(ProgramArgs&&) = delete;

  bool flag_passed(flag_type const type) const noexcept;

  std::optional<std::string_view> value(flag_type const type) const;

  std::string help_menu() const;

private:
  flag_list_type create_flag_list() const;

  flag_info_list_type create_flag_info_list() const;

  flag const& flag_info(flag_type const type) const;

  void check_flag_width(flag const& f) const;
};

}

#endif
