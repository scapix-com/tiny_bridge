cmake_minimum_required(VERSION 3.14...3.26)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.44.tar.gz"
  URL_HASH SHA256=5f321ee2187b2ab940b39325fdf8bd2a127361ffec12338b0d35f9ebc723cf16
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
