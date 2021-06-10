cmake_minimum_required(VERSION 3.0) 
###################################################################################
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
	-Wno-unused-variable
    #-Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    #-Wshadow
    -Wno-write-strings
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

message("build .o")
add_subdirectory(examples) 
add_subdirectory(tests) 
# add_subdirectory(xlpublic)