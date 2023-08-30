add_executable(lab10 main.cpp)

target_link_libraries(lab10 WeatherApp)
target_include_directories(lab10 PUBLIC ${PROJECT_SOURCE_DIR})
