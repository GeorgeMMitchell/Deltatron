find_package(Doxygen REQUIRED)

set(DOXYGEN_OUT_DIR "${CMAKE_BINARY_DIR}/doc" PATH)

set(DOXYGEN_IN_DOXYFILE "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")

set(DOXYGEN_GENERATE_HTML ON CACHE BOOL "Enable Doxygen's HTML generation")

configure_file("${DOXYGEN_IN_DOXYFILE}" "${CMAKE_BINARY_DIR}/doc/Doxyfile" @ONLY)

set(DOXYGEN_DOXYFILE "${CMAKE_BINARY_DIR}/doc/Doxyfile")

add_custom_target("dt_doxygen_target" ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_DOXYFILE}
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/doc"
  COMMENT "Generating Doxygen XML")
