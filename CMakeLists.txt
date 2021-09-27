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
