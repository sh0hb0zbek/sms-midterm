#include "ros/ros.h"
#include "midterm/WeatherStation.h"
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_station_client_node");
  ros::NodeHandle node_handle;
  ros::ServiceClient client = node_handle.serviceClient<midterm::WeatherStation>("weather_station");
  midterm::WeatherStation weather_station_srv;
  std::string location;
  std::cout << "Type 'exit' to quit" << std::endl;
  while (ros::ok())
  {
    std::cout << "Enter Location: ";
    std::cin >> location;
    weather_station_srv.request.GPS_location = location;
    if (location == "exit")
    {
      ROS_INFO("Exiting Application...");
      return 0;
    }
    if (client.call(weather_station_srv))
    {
      std::string resp;
      resp = weather_station_srv.response.weather_type;

      std::cout << "The weather is " << resp << std::endl;
    }
    else
    {
      ROS_ERROR("Not Found Location");
      return 1;
    }
    std::cin.clear();
  }
}
