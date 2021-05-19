cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lab5e_coap)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/coap.c)
zephyr_include_directories(src)

