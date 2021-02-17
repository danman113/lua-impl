# Sets minimum 
cmake_minimum_required(VERSION 3.1)
project(
  clua
  VERSION 1.0
  DESCRIPTION "A simple interperter embedded in c"
  LANGUAGES C
)

find_package(Lua REQUIRED)

file(
  GLOB_RECURSE SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.c
)

include_directories(${LUA_INCLUDE_DIR})

message(${LUA_INCLUDE_DIR})

file(
  GLOB_RECURSE HEADERS
  ${CMAKE_SOURCE_DIR}/src/*.h
)
add_executable(clua ${SOURCES})
target_link_libraries(clua ${LUA_LIBRARIES})

# install(TARGETS "${PROJECT_NAME}" DESTINATION build/)