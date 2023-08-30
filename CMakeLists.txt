cmake_minimum_required(VERSION 3.0.0)
project(lab10 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})
endif()

include_directories(.)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_subdirectory(lib)
add_subdirectory(bin)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4)
FetchContent_MakeAvailable(nlohmann_json)

add_library(WeatherApp lib/weather.h lib/weather.cpp)
target_link_libraries(WeatherApp PUBLIC cpr::cpr)
target_link_libraries(WeatherApp PUBLIC nlohmann_json::nlohmann_json)

add_library(fort lib/fort.hpp lib/fort.h lib/fort.c)
target_link_libraries(WeatherApp PUBLIC fort)
