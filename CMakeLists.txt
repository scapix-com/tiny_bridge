cmake_minimum_required(VERSION 3.14)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.27.tar.gz"
  URL_HASH SHA256=02c767f8fededb8b3bc410ceb0565e0d3a58b478f0de9dc3bba92d9d371e65f3
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
