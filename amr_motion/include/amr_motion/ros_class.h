#ifndef ROS_CLASS_H
#define ROS_CLASS_H

#include <ros/ros.h>
#include <ros/time.h>
#include <iostream>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>
#include "amr_msgs/robotPosition.h"
#include "amr_msgs/robotEnable.h"





class RosClass 
{
public:

    /**
    * @brief  Constructor for the Ros class
    */

    RosClass();

    /**
    * @brief  Destructor for the Ros class
    */
    ~RosClass();
    
    
    
private:
     /**
    * @brief NodeHandle ROS
    */
    ros::NodeHandle nh;

    /*Service Call backs and member functions*/

    bool goalPositionCallback(amr_msgs::robotPosition::Request  &req,
         amr_msgs::robotPosition::Response &res);   

    bool robotActivateCallback(amr_msgs::robotEnable::Request  &req,
         amr_msgs::robotEnable::Response &res);  


     void stopVelocityCommand();  

    



    /**
     * @brief ROS Publishers and services
    */
    ros::Publisher goalPosePub;

    ros::Publisher estopPub;

    ros::Publisher velPub;

    ros::ServiceServer localizationService;

    ros::ServiceServer activationService;

    /*Member variables*/

    bool m_robotEnable;

    

};

#endif