#include "amr_motion.h"
#include <ros/console.h> 

#include "ros_class.h"

/**
* @brief  Constructor for the AmrMotion
*/
AmrMotion::AmrMotion(std::unique_ptr<RosClass> rosPtr):m_getVariables(std::move(rosPtr))
{
    ROS_INFO("AmrMotion Constructor called");
}

/**
* @brief  Destructor for the AmrMotion
*/

AmrMotion::~AmrMotion()
{

}


/**
* @brief Main function
*/
int main(int argc, char** argv)
{

    ros::init(argc, argv, "amr_motion");
    std::unique_ptr<RosClass> rosPtr (new RosClass);    
    AmrMotion amrMotion(std::move(rosPtr));

    ros::Rate rate(1);

    while(ros::ok())
    {

        rate.sleep();
        ros::spinOnce();
    }
    ros::shutdown();
    return 0;
}







