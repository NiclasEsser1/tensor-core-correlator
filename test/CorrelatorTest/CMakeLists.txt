find_package(OpenMP REQUIRED)

add_executable(CorrelatorTest)
target_sources(CorrelatorTest PRIVATE CorrelatorTest.cc Options.cc)
target_include_directories(CorrelatorTest PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(CorrelatorTest PRIVATE tcc Record UnitTest
                                             OpenMP::OpenMP_CXX)

# Define various combinations of parameters to test:
set(ARGS0 -b  4 -c 1 -n 1 -N 32 -r 1 -R 1 -t 32 -V 1)
set(ARGS1 -b  8 -c 1 -n 1 -N 48 -r 1 -R 1 -t 16 -V 1)
set(ARGS2 -b 16 -c 1 -n 1 -N 64 -r 1 -R 1 -t  8 -V 1)
set(ARGS3 -b 16 -c 2 -n 3 -N 32 -r 4 -R 5 -t 64 -V 1)

foreach(idx RANGE 3)
  add_test(NAME CorrelatorTest${idx} COMMAND CorrelatorTest ${ARGS${idx}})
endforeach()
