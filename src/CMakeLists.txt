# SPDX-License-Identifier: zlib-acknowledgement
add_executable(emt)

target_sources(emt PRIVATE
               file1.c)
target_compile_definitions(emt PRIVATE
                           EMT_DEV)
target_include_directories(emt PUBLIC ${CMAKE_PROJECT_DIR}/include)
