cmake_minimum_required(VERSION 3.14...3.26)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.40.tar.gz"
  URL_HASH SHA256=fa85e092c3e3e934700998f477ad9cc7be655d67dcb6345021733f927160fe73
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
