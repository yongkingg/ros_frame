cmake_minimum_required(VERSION 3.0.2)
project(Msg)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  geometry_msgs
  message_generation
)

#==================GNSS Custom Message==================#
add_message_files(
  DIRECTORY GNSS
  FILES
  GNSS.msg
)

#==================Camera Custom Message==================#
add_message_files(
  DIRECTORY Camera
  FILES
  Camera.msg
)

#==================Lidar Custom Message==================#
add_message_files(
  DIRECTORY Lidar
  FILES
  Lidar.msg
)

#==================Planning Custom Message==================#
add_message_files(
  DIRECTORY Planning
  FILES
  Planning.msg
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS 
  std_msgs
  geometry_msgs
  message_runtime
)
