cmake_minimum_required(VERSION 3.0)
project(simulate_event_camera)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(simulate_event_camera simulate_event_camera.cpp)
target_link_libraries(simulate_event_camera ${OpenCV_LIBS})
