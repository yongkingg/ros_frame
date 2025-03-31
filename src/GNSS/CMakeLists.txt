cmake_minimum_required(VERSION 3.0.2)
project(GNSS)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  Msg
  message_generation
  morai_msgs
)

generate_messages(
   DEPENDENCIES
   geometry_msgs
   std_msgs
)
 
catkin_package(
  CATKIN_DEPENDS 
  roscpp
  std_msgs
  geometry_msgs
  message_runtime
  Msg
  morai_msgs
)

include_directories(
 include 
 ${catkin_INCLUDE_DIRS}
)

add_executable(gps src/GNSS.cpp)
target_link_libraries(gps ${catkin_LIBRARIES})

