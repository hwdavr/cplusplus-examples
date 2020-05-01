cmake_minimum_required(VERSION 3.10)
project(casting)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined")

message("Checking compiler: ")
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using Clang
  message("using Clang")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wabi -Wconversion -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  message("using GCC")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wabi -Wconversion -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
  message("using Intel C++")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  message("using Visual Studio C++")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()


add_executable(casting casting_example.cpp)