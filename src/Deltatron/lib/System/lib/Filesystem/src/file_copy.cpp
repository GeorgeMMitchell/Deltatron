#include <dt/Filesystem.hpp>

#include <fstream>

std::string dt::file_copy(stdfs::path const& file_path) {
  if (!stdfs::exists(file_path))
    return {};

  auto       in_file   = std::ifstream{file_path, std::ios::binary | std::ios::ate};
  auto const file_size = std::streamoff{in_file.tellg()};
  auto       file_data = std::string(static_cast<std::string::size_type>(file_size), '\0');

  in_file.seekg(0);

  in_file.read(&file_data[0], file_size);

  return file_data;
}
