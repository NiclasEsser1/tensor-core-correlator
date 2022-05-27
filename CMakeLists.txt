cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(
  tensor_core_correlator
  DESCRIPTION "Tensor-Core Correlator"
  VERSION 0.5
  HOMEPAGE_URL https://git.astron.nl/RD/tensor-core-correlator
  LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
option(BUILD_SHARED_LIBS "Create shared libraries" True)
option(BUILD_TESTING "Build tests" False)

# Use CMAKE_INSTALL_PREFIX when searching for libraries
include(GNUInstallDirs)
list(APPEND CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_FULL_LIBDIR})

# Add cudawrappers dependency
add_subdirectory(external/cudawrappers)

# Set up libtcc
add_subdirectory(libtcc)

# Set up tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

# Install project cmake targets
include(CMakePackageConfigHelpers)
configure_file(cmake/${PROJECT_NAME}-config.cmake.in
               ${PROJECT_NAME}-config.cmake @ONLY)
write_basic_package_version_file(
  ${PROJECT_NAME}-config-version.cmake
  VERSION ${cudawrappers_VERSION}
  COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

# --- auto-ignore build directory
if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
  file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()
