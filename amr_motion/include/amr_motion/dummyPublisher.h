#ifndef ROS_CLASS_H
#define ROS_CLASS_H

#include <ros/ros.h>
#include <ros/time.h>
#include <iostream>

#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include "amr_msgs/dummyMessage.h"
#include <sstream>
#include <string>

#include <vector>
#include <time.h>       /* time */
#include <cstdlib> 
#include <ctime> 


#define MAXSIZE 100
class DummyPublisher 
{
public:

    /**
    * @brief  Constructor for the Ros class
    */

    DummyPublisher();

    /**
    * @brief  Destructor for the Ros class
    */
    ~DummyPublisher();
    
    void populateVector();
    
private:
     /**
    * @brief NodeHandle ROS
    */
    ros::NodeHandle nh;

    /*Service Call backs and member functions*/

    void floatCallback(const std_msgs::Float32 &msg);
    


    void publishVectorMessage();


    /**
     * @brief ROS Publishers and services
    */
    ros::Publisher stringPub;

    ros::Publisher vectorStringPub;

    ros::Subscriber floatSub;



    /*Member variables*/

    //bool m_robotEnable;

    std_msgs::String m_floatToString;

    std::vector<float> m_floatNumbers;

};

#endif