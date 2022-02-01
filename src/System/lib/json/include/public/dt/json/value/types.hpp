#ifndef JSON_VALUE_TYPES_HEADER
#define JSON_VALUE_TYPES_HEADER

#include <optional>
#include <string>
#include <map>
#include <variant>
#include <vector>

namespace dt::json {

class value;

using object_type = std::map<std::string, value>;

using array_type = std::vector<value>;

using int_type = int;

using float_type = float;

using value_type = std::variant<object_type, array_type, int_type, float_type, bool, std::string, std::nullopt_t>;

}

#endif // JSON_VALUE_TYPES_HEADER
