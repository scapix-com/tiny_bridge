cmake_minimum_required(VERSION 3.14...3.26)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.43.tar.gz"
  URL_HASH SHA256=4840662739925f1d815e49e69c01dfab642f54ef0dc3808e0aa75accfa38a4cd
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
