cmake_minimum_required(VERSION 3.20...3.27)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v2.0.1.tar.gz"
  URL_HASH SHA256=a9477bbefb43b6fabdc2dc044207fe42cca63999c60b6baf06ba0c62fa116ec5
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)
target_include_directories(bridge PRIVATE .)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
