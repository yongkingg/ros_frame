cmake_minimum_required(VERSION 3.0.2)
project(Main)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation 
  geometry_msgs 
  morai_msgs
  Msg
)

generate_messages(
  DEPENDENCIES
  std_msgs  
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib 
  Msg
  morai_msgs
)

include_directories(
  include
  src
  ${catkin_INCLUDE_DIRS}
)

add_library(myHeader 
  src/Global/Global.cpp
  src/Parser/Parser.cpp
  src/Control/Control.cpp
  src/Planning/Planning.cpp
  src/Planning/GPP.cpp
)

target_link_libraries(myHeader ${catkin_LIBRARIES})

add_executable(main src/main.cpp)
target_link_libraries(main myHeader
  ${catkin_LIBRARIES}
  yaml-cpp
)

add_executable(gpp src/Planning/GPP.cpp)
target_link_libraries(gpp myHeader
  ${catkin_LIBRARIES}
  yaml-cpp
)
