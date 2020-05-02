cmake_minimum_required(VERSION 3.14)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.10.tar.gz"
  URL_HASH SHA256=7d6903a9a980433217d272e237c0d1ddbfd54e6770ca49d9e58397df2a62f13d
)
FetchContent_MakeAvailable(cmodule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc

add_library(bridgelib SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridgelib "com.scapix.bridge" contact.h)
