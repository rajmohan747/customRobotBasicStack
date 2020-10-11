#ifndef AUTO_LOCALIZATION_H
#define AUTO_LOCALIZATION_H

#include <iostream>
#include <ros/ros.h>
#include "ros_class.h"
#include <ros/package.h>
#include <fstream>
#include <chrono>
#include <mutex>

using namespace std;

class AmrMotion
{
public:
    
    /**
    * @brief  Constructor for the AmrMotion
    */
    AmrMotion (std::unique_ptr<RosClass> rs);
    
    /**
    * @brief  Destructor for the AmrMotion
    */
    ~AmrMotion();

private:

    /*Member variables*/
    std::unique_ptr<RosClass>  m_getVariables;


};
#endif
