# add_subdirectory(tests)

# set(base_SRCS  Condition.cpp CountDownLatch.cpp Exception.cpp Thread.cpp)

# add_library(xl_base ${base_SRCS})
# target_link_libraries(xl_base pthread rt)
# rt 时间库

# install(TARGETS muduo_base DESTINATION lib)
# file(GLOB HEADERS "*.h")
# install(FILES ${HEADERS} DESTINATION include/muduo/base)

# if(NOT CMAKE_BUILD_NO_EXAMPLES)
#   add_subdirectory(tests)
# endif()