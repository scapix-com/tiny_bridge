cmake_minimum_required(VERSION 3.14...3.26)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.45.tar.gz"
  URL_HASH SHA256=3bfd947a40754d8a721a9c5870402faba6cafa89f75bf149d933408a3f544497
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
