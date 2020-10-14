cmake_minimum_required(VERSION 2.8.3)
project(amr_motion)

add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  
  geometry_msgs
  roscpp
  rospy
  std_msgs
  amr_msgs
)





#add_service_files(
#   FILES
#   robotEnable.srv
#   robotPosition.srv
# )


#generate_messages(
#  DEPENDENCIES
#  std_msgs
#)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    
    geometry_msgs
    roscpp
    rospy
    std_msgs
    
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include/amr_motion
)


add_executable(amr_motion
  src/amr_motion.cpp
  src/ros_class.cpp

)

target_link_libraries(amr_motion
  ${catkin_LIBRARIES}
)


add_executable(dummyPublisher
  src/dummyPublisher.cpp

)

target_link_libraries(dummyPublisher
  ${catkin_LIBRARIES}
)