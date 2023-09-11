include_directories(${PROJECT_SOURCE_DIR}/examples/mynet/src/include/)
file(GLOB_RECURSE pine_sources ${PROJECT_SOURCE_DIR}/examples/mynet/src/*.cpp)
message ("PROJECT_SOURCE_DIR:"  ${PROJECT_SOURCE_DIR})
add_library(pine_shared SHARED ${pine_sources})
