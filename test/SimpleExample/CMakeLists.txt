add_executable(SimpleExample)
set_property(TARGET SimpleExample PROPERTY CUDA_ARCHITECTURES OFF)
target_sources(SimpleExample PRIVATE SimpleExample.cu)
target_include_directories(SimpleExample PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(SimpleExample PRIVATE tcc)

add_test(NAME SimpleExample COMMAND SimpleExample)
