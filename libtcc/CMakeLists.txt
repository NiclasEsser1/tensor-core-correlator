# Create tcc library
add_library(tcc)
# Add source files
target_sources(tcc PRIVATE Correlator.cc CorrelatorKernel.cc Kernel.cc)

set(tcc_inc
  Correlator.h
  CorrelatorKernel.h
  Kernel.h
)
# Add public header
set_target_properties(tcc PROPERTIES PUBLIC_HEADER Correlator.h CorrelatorKernel.h Kernel.h)
# Add includes
target_include_directories(
  tcc PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
             $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
# Add links
target_link_libraries(tcc PUBLIC cudawrappers::cu cudawrappers::nvrtc)
# Install libraries and headers
install(
  TARGETS tcc
  EXPORT tcc-config # export tcc cmake targets
  COMPONENT tcc
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
# Install tcc cmake targets
install(
  EXPORT tcc-config
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
# Embed CUDA code
include(${CMAKE_SOURCE_DIR}/cmake/Utils.cmake)
include_cuda_code(tcc kernel/TCCorrelator.cu)

install(FILES ${tcc_inc} DESTINATION include/libtcc/)