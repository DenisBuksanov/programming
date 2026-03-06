cmake_minimum_required(VERSION 3.10)

project(cripto_cmake)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include) 
set(LIB_TYPE STATIC CACHE STRING "Library type")
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES ${SOURCE_DIR}/cripto.c)

include_directories(${INCLUDE_DIR})

add_library(UTIL_LIB ${LIB_TYPE} ${SOURCES}) 

add_executable(cmakecripto ${SOURCE_DIR}/criptomain.c)
target_link_libraries(cmakecripto UTIL_LIB)
