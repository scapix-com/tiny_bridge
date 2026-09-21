cmake_minimum_required(VERSION 3.20...3.27)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.6.0.tar.gz
  URL_HASH SHA256=7ee432c13bf91d3c86d2ab675ba379cea079e39b9efbe183f2ab4e7b479cee90
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)
target_include_directories(bridge PRIVATE .)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
