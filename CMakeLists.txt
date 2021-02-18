# Sets minimum 
cmake_minimum_required(VERSION 3.1)
include(FetchContent)

project(
  clua
  VERSION 1.0
  DESCRIPTION "A simple interperter embedded in c"
  LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})
message("> using lua from " ${LUA_INCLUDE_DIR})

set(JSON_BuildTests OFF CACHE INTERNAL "") # makes it faster
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  cpphttplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
)
FetchContent_MakeAvailable(cpphttplib)

file(
  GLOB_RECURSE SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(
  GLOB_RECURSE HEADERS
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${uwebsockets_SOURCE_DIR}/src/**.h
)

add_executable(clua ${SOURCES})
target_link_libraries(clua PUBLIC ${LUA_LIBRARIES})
target_link_libraries(clua PUBLIC httplib::httplib)
target_link_libraries(clua PRIVATE nlohmann_json::nlohmann_json)

# install(TARGETS "${PROJECT_NAME}" DESTINATION build/)