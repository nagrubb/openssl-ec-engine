cmake_minimum_required(VERSION 2.8.11)
project(ng-engine)

find_package(OpenSSL REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})

add_library(ng SHARED
  engine.c
  ec_key_impl.c
)

target_link_libraries(ng crypto)
