#include <ros/console.h> 
#include "dummyPublisher.h"


/**
* @brief  Constructor for the RosClass
*/
DummyPublisher::DummyPublisher()
{

    ROS_INFO("DummyPublisher Constructor called ");
    
    
    /*Publishers*/

    stringPub            = nh.advertise<std_msgs::String>("/dummyString",1);
    vectorStringPub      = nh.advertise<amr_msgs::dummyMessage>("/dummyVectorString",1);
    /*Subscribers*/

    floatSub             = nh.subscribe("/dummyFloat", 1, &DummyPublisher::floatCallback,this);

    populateVector();
}

    /**
    * @brief  Destructor for the RosClass
    */

DummyPublisher::~DummyPublisher()
{

}



void DummyPublisher::floatCallback(const std_msgs::Float32 &msg)
{
    ROS_INFO("Subscribed float value : %f",msg.data);
    float dummyValue  = msg.data;

    std::ostringstream ss;
    ss << dummyValue;
    std::string str(ss.str());


    ROS_INFO("Converted string is %s",str.c_str());
    m_floatToString.data = str;
    stringPub.publish(m_floatToString);
    
}


void DummyPublisher::populateVector()
{

    m_floatNumbers.clear();
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
 
    for (int count=1; count < MAXSIZE; ++count)
    {
        float currentNumber = std::rand()%MAXSIZE;
        m_floatNumbers.push_back(currentNumber);
     }

    std::sort(m_floatNumbers.begin(), m_floatNumbers.end()); 


    publishVectorMessage();

}


void DummyPublisher::publishVectorMessage()
{
    amr_msgs::dummyMessage dummy_message;
    std::vector<std::string> stringMessage;
    stringMessage.clear();
    //ROS_INFO("Size of vector : %d",m_floatNumbers.size());
    for (auto x : m_floatNumbers) 
    { 
        std::ostringstream ss;
        ss << x;
        std::string str(ss.str());
        stringMessage.push_back(str);
    }
    dummy_message.message = stringMessage;
    vectorStringPub.publish(dummy_message);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "dummyPublisher");
    DummyPublisher dummy;
    ros::Rate rate(1);

    while(ros::ok())
    {
        dummy.populateVector();
        rate.sleep();
        ros::spinOnce();
    }
    ros::shutdown();
    return 0;
}
