cmake_minimum_required(VERSION 3.20...3.27)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.4.0.tar.gz
  URL_HASH SHA256=0f6770d1c6e8865577461eab8236e424e7b4da91beefa79375f9f9ff519ffc6b
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)
target_include_directories(bridge PRIVATE .)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
