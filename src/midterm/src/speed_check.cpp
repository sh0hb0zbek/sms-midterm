#include "ros/ros.h"

#include "std_msgs/Float32.h"

float PLATE_NUMBER;
float SPEED;

ros::Publisher speed_check;


void subCallback(const std_msgs::Float32::ConstPtr& speed_limit)
{
   ros::NodeHandle callback_node_handle;
   if (callback_node_handle.getParam("plate_number", PLATE_NUMBER))
   {
      if (callback_node_handle.getParam("speed", SPEED))
      {
         if (SPEED > speed_limit->data)
         {
            std_msgs::Float32 over_speed_msg;
            over_speed_msg.data = PLATE_NUMBER;
            speed_check.publish(over_speed_msg);
         }
      }
      else
      {
         ROS_WARN(" No Value set for speed parameter.");
      }
   }
   else
   {
      ROS_WARN("No Value set for plate_number parameter.");
   }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_check_node");

  ros::NodeHandle node_handle;

  speed_check = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Subscriber speed_limit = node_handle.subscribe("speed_limit", 10, subCallback);

  ros::spin();

  return 0;
}
