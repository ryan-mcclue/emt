# SPDX-License-Identifier: zlib-acknowledgement
cmake_minimum_required(VERSION 3.17)
project(EMT
        VERSION 0.0.1
        DESCRIPTION "Embedded testing structure"
        LANGUAGES C)
set_property(GLOBAL PROPERTY C_STANDARD 11)

include(cmake/CPM.cmake)

################
# DEPENDENCIES #
################

find_package(cmocka QUIET)
if(NOT cmocka_FOUND)
  CPMAddPackage(
    NAME cmocka
    GITHUB_REPOSITORY https://git.cryptomilk.org/projects/cmocka.git/
    VERSION 1.1.5
    GIT_TAG cmocka-1.1.5
    OPTIONS
      "WITH_EXAMPLES OFF"
      "CMAKE_BUILD_TYPE DEBUG"
  )
endif()

CPMAddPackage(
  NAME printf
  GITHUB_REPOSITORY mpaland/printf
  VERSION 4.0.0
  DOWNLOAD_ONLY
)

add_library(printf INTERFACE)
target_sources(printf INTERFACE
  ${printf_SOURCE_DIR}/printf.c
)
target_include_directories(printf SYSTEM INTERFACE 
  ${printf_SOURCE_DIR}
)

###############
# SOURCE TREE #
###############
add_subdirectory(src)
