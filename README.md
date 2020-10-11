# customRobotNavigation
A basic version of navigation with a custom differential driven robot .

## Prerequisites

Create and setup the workspace 


```
mkdir catkin_ws

cd catkin_ws

mkdir src

cd src

catkin_init_workspace
```

## Build

Clone the repository inside workspace and build it using the following command

```
git clone https://github.com/rajmohan747/customRobotNavigation.git

catkin_make -DCMAKE_BUILD_TYPE=Release
```

## Execution in simulation environment

Launch the files in the following sequence

```
roslaunch amr_bringup amr.launch

roslaunch amr_navigation amr_navigation.launch
```

After launching the above two files,you should be able to see the Gazebo and Rviz for the simulated environment.


##Testing in simulation

Now robot can be moved in the simulation environment either using keyboard teleop or Rviz or with the ros service call(robot_goal).
Launch the following command for teleoperating the robot  

```
roslaunch amr_bringup amr_teleop.launch 
```

The amr_motion node in the amr_motion package can be used for enabling the robot the robot and setting the target location for robot.

For enabling the robot,use the following ros service call 

```
rosservice call /robot_activate "robotEnable: true" 
```

The command for robot for moving to any location can be given through either Rviz or through the following ros service

```
rosservice call /robot_goal "x: 0.0
y: 0.0
z: 0.0
w: 0.0" 

```

**Note** :  x,y are the x-y cordinates of the target location in map frame and z,w the quaternion values of the target location.
     Also,make sure if the ros service robotEnable is set as "false" ,robot won't be moving irrespective of whether the 
     command is given from keyboard teleop,Rviz,or  service call (robot_activate)
