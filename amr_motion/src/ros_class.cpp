#include <ros/console.h> 
#include "ros_class.h"


/**
* @brief  Constructor for the RosClass
*/
RosClass::RosClass():m_robotEnable(false)
{

    ROS_INFO("RosClass Constructor called ");
    
    
    /*Publishers*/
    goalPosePub         = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",1);

    estopPub            = nh.advertise<std_msgs::Bool>("/e_stop",1);

    velPub              = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);
    /*Services*/
    localizationService = nh.advertiseService("robot_goal", &RosClass::goalPositionCallback,this);

    activationService   = nh.advertiseService("robot_activate", &RosClass::robotActivateCallback,this);

}

    /**
    * @brief  Destructor for the RosClass
    */

RosClass::~RosClass()
{

}




/** 
* @brief  Service call back which can be used to send the robot using the given cordinates
*/
bool RosClass::goalPositionCallback(amr_msgs::robotPosition::Request  &req,
         amr_msgs::robotPosition::Response &res)
{

    geometry_msgs::PoseStamped goalPose;

    goalPose.header.stamp = ros::Time(0);
    goalPose.header.frame_id = "/map";

    goalPose.pose.position.x    = req.x;
    goalPose.pose.position.y    = req.y;
    goalPose.pose.orientation.z = req.z;
    goalPose.pose.orientation.w = req.w;

    if(m_robotEnable)
    {
        goalPosePub.publish(goalPose);
        ROS_INFO("Goal Pose Published from service call");
    }
    res.result = true;
    return true;
}


/** 
* @brief  Service call back which can be used to activate/deactivate the robot
*/
bool RosClass::robotActivateCallback(amr_msgs::robotEnable::Request  &req,
         amr_msgs::robotEnable::Response &res)
{
    std_msgs::Bool estopStatus;

    m_robotEnable = req.robotEnable;
    if(m_robotEnable)
    {
        estopStatus.data = false;
        ROS_INFO("Robot activated from service call");
    }
    else
    {
        stopVelocityCommand();
        estopStatus.data = true;
        ROS_INFO("Robot de-activated from service call");
        
    }
    estopPub.publish(estopStatus);
    res.result = true;
    return true;
}

/*To ensure robot stops even if the service call (robot_activate) done while robot in middile of motion*/
void RosClass::stopVelocityCommand()
{
    geometry_msgs::Twist velCommand;
    velCommand.linear.x  = 0.0;
    velCommand.angular.z = 0.0;
    velPub.publish(velCommand);
}

