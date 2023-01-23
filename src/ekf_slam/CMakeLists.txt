cmake_minimum_required(VERSION 3.0.2)
project(ekf_slam)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf2
  turtlesim
  std_msgs
  message_generation
)

add_service_files(
  DIRECTORY srv
  FILES
  goal_pose.srv
 )

generate_messages()


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ekf_slam
  CATKIN_DEPENDS gazebo roscpp rospy tf2 turtlesim message_runtime std_msgs
#  DEPENDS system_lib

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(ekf src/ekf_slam.cpp)
target_link_libraries(ekf ${catkin_LIBRARIES})

add_executable(mm src/motion_model_server.cpp)
target_link_libraries(mm ${catkin_LIBRARIES})

