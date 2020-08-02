cmake_minimum_required(VERSION 3.14)

project(tiny_bridge)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.21.tar.gz"
  URL_HASH SHA256=c27e8467f4c4650f8f98a062fe027ee29ff5442dfa1f47838ca3c5e82e3eb453
)
FetchContent_MakeAvailable(cmodule)

add_library(bridge SHARED contact.h)

find_package(Scapix REQUIRED)
scapix_bridge_headers(bridge "com.example.bridge" contact.h)
