#include <dt/Deltatron.hpp>

#include <exception>
#include <iostream>

#include <cstdlib>

int main(int argc, dt::Deltatron::argv_type const argv) {
  try {
    return dt::Deltatron{argc, argv}.run();

  } catch (dt::exception const& e) {
    std::cerr << "deltatron: dt::exception caught in main: \"" << e.what() << '"' << std::endl;

  } catch(std::exception const& e) {
    std::cerr << "deltatron: std::exception caught in main: \"" << e.what() << '"' << std::endl;

  } catch (...) {
    std::cerr << "deltatron: unknown type caught in main" << std::endl;

  }

  return EXIT_FAILURE;
}
