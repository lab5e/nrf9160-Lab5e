cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Add custom signing key to the bootloader (mcuboot) config
set(mcuboot_CONF_FILE
  ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/bootloader/mcuboot/boot/zephyr/prj.conf
  ${CMAKE_CURRENT_SOURCE_DIR}/mcuboot.conf
)

project(lab5e_fota)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/fota.c)
zephyr_include_directories(src)
