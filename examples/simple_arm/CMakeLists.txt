cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package (Qt5Core REQUIRED)
find_package (Qt5Widgets REQUIRED)
set (CMAKE_AUTOMOC ON)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(KeyboardGUIPlugin MODULE src/KeyboardGUIPlugin.cc)
target_link_libraries(KeyboardGUIPlugin ${GAZEBO_LIBRARIES} Qt5::Core)

add_library(KeysToJointsPlugin MODULE src/KeysToJointsPlugin.cc)
target_link_libraries(KeysToJointsPlugin ${GAZEBO_LIBRARIES} Qt5::Core)