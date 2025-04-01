cmake_minimum_required(VERSION 3.0.2)
project(Camera)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
  sensor_msgs
)
#=============== 커스텀메세지 ===============#

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

install(FILES configuration.yaml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


catkin_install_python(PROGRAMS
  src/LaneDetection.py
  src/TrafficLightDetection.py
  src/RoadSignDetection.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
