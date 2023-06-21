cmake_minimum_required(VERSION 3.14...3.26)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.41.tar.gz"
  URL_HASH SHA256=2372c59bb3c9799eaec884e2c0cac414dfd108566da6693636903eb63ffd9819
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
