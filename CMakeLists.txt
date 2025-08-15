cmake_minimum_required(VERSION 3.20...3.27)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v2.0.2.tar.gz"
  URL_HASH SHA256=9655d2ecfcd70a78093ae03275479d5e24a9c7e967476a290c34c1089a3313b5
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)
target_include_directories(bridge PRIVATE .)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
