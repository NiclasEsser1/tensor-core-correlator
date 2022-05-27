find_package(OpenMP REQUIRED)
find_package(OpenCL REQUIRED)

add_executable(OpenCLCorrelatorTest)
target_sources(OpenCLCorrelatorTest PRIVATE OpenCLCorrelatorTest.cc)
target_include_directories(OpenCLCorrelatorTest PRIVATE ${CMAKE_SOURCE_DIR}
                                                        ${OpenCL_INCLUDE_DIRS})
target_link_libraries(OpenCLCorrelatorTest PRIVATE ${OpenCL_LIBRARIES}
                                                   OpenMP::OpenMP_CXX)

add_test(
  NAME OpenCLCorrelatorTest
  COMMAND OpenCLCorrelatorTest
  # Specify working directory so the kernel code is found
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
