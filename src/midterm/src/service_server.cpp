#include "ros/ros.h"
#include "midterm/WeatherStation.h"
// #include "cpr.cpr.h"

bool determineWeatherType(midterm::WeatherStation::Request &req,
                          midterm::WeatherStation::Response &res)
{
  std::string location = req.GPS_location;
  // we tried to use weather api requests but it shows error even we install cpr library successfully
  // std::string url = "http://api.weatherapi.com/v1/current.json?key=a053b73131224ef8ae2225628222304&q=" + location;
  // cpr::Response r = cpr::Get(cpr::Url{url});
  
  if (location == "Seoul") res.weather_type = "sunny";
  else if (location == "Istanbul") res.weather_type = "cloudy";
  else if (location == "Sydney") res.weather_type = "windy";
  else if (location == "London") res.weather_type = "rainy";
  else if (location == "Siberia") res.weather_type = "stormy";
  else return false;
  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_station_server_node");
  ros::NodeHandle node_handle;
  ros::ServiceServer service = node_handle.advertiseService("weather_station", determineWeatherType);
  ROS_INFO("Weather Station Server Running...");
  ros::spin();
  return 0;
}
