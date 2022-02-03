set(DELTATRON_BUILD_DOCUMENTATION ON CACHE BOOL "Build the Deltatron documentation")
set(DELTATRON_DOCUMENTATION_FORMAT "html" CACHE STRING "Format to generation the Deltatron documentation in. Possible values are 'html', 'pdf', and 'text'.")


if (DELTATRON_BUILD_DOCUMENTATION)

  add_subdirectory("Doxygen")

  set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_MODULE_PATH})

  find_package("Sphinx" REQUIRED)

  add_custom_target("dt_sphinx_target" ALL
    COMMAND ${SPHINX_EXECUTABLE} -b html ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    -Dbreathe_projects.Deltatron="${CMAKE_CURRENT_BINARY_DIR}/Doxygen/xml"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating Sphinx HTML")

endif(DELTATRON_BUILD_DOCUMENTATION)
