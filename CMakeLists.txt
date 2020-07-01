cmake_minimum_required(VERSION 3.14)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.17.tar.gz"
  URL_HASH SHA256=eb82911bad72797a1ba9668b123358f7a64b7eea3e336235446f886c8a10469e
)
FetchContent_MakeAvailable(cmodule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
