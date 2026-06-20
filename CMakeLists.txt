cmake_minimum_required(VERSION 3.20...3.27)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.3.0.tar.gz
  URL_HASH SHA256=da4cd5b12524041171acc80c2befe0e1de8ae59ea4dc5fc415de43e532d179dd
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)
target_include_directories(bridge PRIVATE .)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
