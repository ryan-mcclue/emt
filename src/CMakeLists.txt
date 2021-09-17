# SPDX-License-Identifier: zlib-acknowledgement
include(CTest)
add_executable(emt)

find_library(CMOCKA_LIB
             NAMES cmocka 
             REQUIRED)

target_sources(emt PRIVATE
               emt.c)
target_link_libraries(emt PRIVATE
                      ${CMOCKA_LIB})

add_test(NAME emt.test
         COMMAND emt)


#target_compile_definitions(emt PRIVATE
#                           EMT_DEV)
#target_include_directories(emt PUBLIC ${CMAKE_PROJECT_DIR}/include)
