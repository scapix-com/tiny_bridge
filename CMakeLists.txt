cmake_minimum_required(VERSION 3.14)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.19.tar.gz"
  URL_HASH SHA256=755bf9846b0626b4038e01e9ad413e27358f48ce9dbcfdee43917d21e6ee8fd9
)
FetchContent_MakeAvailable(cmodule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
