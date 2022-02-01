add_library("json")

target_link_libraries("json"
  PRIVATE
    "dt_build_requirements"
  PUBLIC
    "dt_exception")

target_include_directories("json"
  PRIVATE
    "include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("json"
  PRIVATE
    "include/private/dt/json/Parser.hpp"
    "src/Parser.cpp"

    "include/private/dt/json/Lexer/token.hpp"
    "src/Lexer/token.cpp"
    "include/private/dt/json/Lexer/Scanner.hpp"
    "src/Lexer/Scanner.cpp"
    "include/private/dt/json/Lexer.hpp"
    "src/Lexer.cpp"

    "include/private/dt/json/throw_exception.hpp"
    "src/throw_exception.cpp"

    "include/public/dt/json/value/types.hpp"
    "include/public/dt/json/value.hpp"
    "src/value.cpp"
    "include/public/dt/json/document.hpp"
    "src/document.cpp")
