cmake_minimum_required(VERSION 3.5)

project(ws_video2jpg VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON) 



# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# !OpenCV

set(PROJECT_SOURCES
    src/main.cpp
)

add_executable(ws_video2jpg ${PROJECT_SOURCES})
target_link_libraries(ws_video2jpg ${OpenCV_LIBS})
