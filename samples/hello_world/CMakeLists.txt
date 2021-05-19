#
# Copyright (c) 2019 Exploratory Engineering
#

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(serial_lte_modem)

target_sources(app PRIVATE src/main.c)
