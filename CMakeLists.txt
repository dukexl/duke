cmake_minimum_required(VERSION 3.0) 
###################################################################################
#默认不开启，开启的两种方法：
#在CMakeLists.txt中添加 set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#在命令行中添加-DCMAKE_EXPORT_COMPILE_COMMANDS=on
#开启后，其生成的文件compile_commands.json，包含所有编译单元所执行的指令
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS ON)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(total)

if (CMAKE_BUILD_TYPE) 
else() 
	set(CMAKE_BUILD_TYPE RELEASE) 
endif()

set(CXX_FLAGS
    -g
    # -DVALGRIND
    -DCHECK_PTHREAD_RETURN_VALUE
    -D_FILE_OFFSET_BITS=64
    -Wall
    -Wextra
    #-Werror
    #-Wconversion
    -Wno-unused-parameter
	-Wno-unused-value
    -Wno-unused-result
	-Wno-unused-variable
    #-Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    #-Wshadow
    -Wno-write-strings
    -Wno-format-truncation
	-Wno-char-subscripts 
    -march=native
    -std=c++11
    -rdynamic ) 
	
if(CMAKE_BUILD_BITS EQUAL 32) 
	list(APPEND CXX_FLAGS "-m32") 
endif() 

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++") 
set(CMAKE_CXX_FLAGS_DEBUG "-O0") 
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG") 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message("------------ Options -------------") 
message("  CMAKE_PROJECT: ${PROJECT_NAME}") 
message("  CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}") 
message("  CMAKE_BUILD_BITS: ${CMAKE_BUILD_BITS}") 
message("  CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}") 
message("  EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")
message("  LIBRARY_OUTPUT_PATH: ${LIBRARY_OUTPUT_PATH}") 

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

#find_package(CURL) 
#if(CURL_FOUND) 
#	message(STATUS "found curl") 
#endif()
include_directories(./)
add_subdirectory(examples) 
add_subdirectory(tests) 
add_subdirectory(xlpublic)