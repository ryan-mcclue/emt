# SPDX-License-Identifier: zlib-acknowledgement

add_library(adder STATIC)

target_sources(adder PRIVATE
  adder/adder.c
)
target_include_directories(adder PUBLIC
  adder 
)
target_compile_definitions(adder PRIVATE
  NO_ERRNO  
)
target_link_libraries(adder PRIVATE
  printf
)

# CMAKE_MODULE_PATH
# opt to use CPM as scattered, e.g. just download, package, pkg-config etc.  

# ${PROJECT_SOURCE_DIR}

#add_executable(emt)
#
#find_library(CMOCKA_LIB
#             NAMES cmocka 
#             REQUIRED)
#
#target_sources(emt PRIVATE
#               emt.c)
#target_link_libraries(emt PRIVATE
#                      ${CMOCKA_LIB})


#target_compile_definitions(emt PRIVATE
#                           EMT_DEV)
#target_include_directories(emt PUBLIC ${CMAKE_PROJECT_DIR}/include)
