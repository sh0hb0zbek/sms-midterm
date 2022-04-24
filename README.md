# sms-midterm

- Creating the midterm 5
```bash
ros@ubuntu:~/catkin_ws$ mkdir midterm
ros@ubuntu:~/catkin_ws$ cd midterm/
ros@ubuntu:~/catkin_ws/midterm$ mkdir src
ros@ubuntu:~/catkin_ws/midterm$ cd src
ros@ubuntu:~/catkin_ws/midterm/src$ catkin_create_pkg midterm roscpp
Created file midterm/package.xml
Created file midterm/CMakeLists.txt
Created folder midterm/include/midterm
Created folder midterm/src
Successfully created files in /home/ros/catkin_ws/midterm/src/midterm. Please adjust the values in package.xml.
ros@ubuntu:~/catkin_ws/midterm/src$mkdir launch
---------------------------------------------------------------
UPDATE src FOLDER CPP CODES AND C_MAKE FILE
---------------------------------------------------------------
ros@ubuntu:~/catkin_ws/midterm/src$ cd ..
ros@ubuntu:~/catkin_ws/midterm$ catkin_make
Base path: /home/ros/catkin_ws/midterm
Source space: /home/ros/catkin_ws/midterm/src
Build space: /home/ros/catkin_ws/midterm/build
Devel space: /home/ros/catkin_ws/midterm/devel
Install space: /home/ros/catkin_ws/midterm/install
####
#### Running command: "make cmake_check_build_system" in "/home/ros/catkin_ws/midterm/build"
####
####
#### Running command: "make -j2 -l2" in "/home/ros/catkin_ws/midterm/build"
####
[  0%] Built target std_msgs_generate_messages_cpp
[  0%] Built target sensor_msgs_generate_messages_cpp
[  0%] Built target _midterm_generate_messages_check_deps_WeatherStation
[ 13%] Built target speed_limit
[ 26%] Built target speed_check
[ 26%] Built target sensor_msgs_generate_messages_py
[ 26%] Built target std_msgs_generate_messages_py
[ 26%] Built target sensor_msgs_generate_messages_nodejs
[ 26%] Built target std_msgs_generate_messages_nodejs
[ 26%] Built target std_msgs_generate_messages_lisp
[ 26%] Built target sensor_msgs_generate_messages_lisp
[ 26%] Built target std_msgs_generate_messages_eus
[ 26%] Built target sensor_msgs_generate_messages_eus
[ 33%] Built target midterm_generate_messages_cpp
[ 46%] Built target midterm_generate_messages_nodejs
[ 53%] Built target midterm_generate_messages_py
[ 66%] Built target midterm_generate_messages_eus
[ 73%] Built target midterm_generate_messages_lisp
[100%] Built target service_server
[100%] Built target service_client
[100%] Built target midterm_generate_messages
ros@ubuntu:~/catkin_ws/midterm$ 

```
- Clone the repository 
```bash
ros@ubuntu:~/catkin_ws$ mkdir midterm
ros@ubuntu:~/catkin_ws$ cd midterm
ros@ubuntu:~/catkin_ws/midterm$ git clone "https://github.com/sh0hb0zbek/sms-midterm.git"
```
- Start roscore
```bash
ros@ubuntu:~/catkin_ws/midterm$ roscore
... logging to /home/ros/.ros/log/c198ccb2-c374-11ec-b91c-974d1a0c2498/roslaunch-ubuntu-75350.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://ubuntu:33377/
ros_comm version 1.15.14


SUMMARY
========

PARAMETERS
 * /rosdistro: noetic
 * /rosversion: 1.15.14

NODES

auto-starting new master
process[master]: started with pid [75358]
ROS_MASTER_URI=http://ubuntu:11311/

setting /run_id to c198ccb2-c374-11ec-b91c-974d1a0c2498
process[rosout-1]: started with pid [75368]
started core service [/rosout]
ros@ubuntu:~/catkin_ws/midterm$
```
- Compile the project
```bash
ros@ubuntu:~/catkin_ws/midterm$ catkin_make
```
### Task #1
- check the midterm services in the new tab
```bash
ros@ubuntu:~/catkin_ws/midterm$ source devel/setup.bash 
ros@ubuntu:~/catkin_ws/midterm$ rossrv list
--- omitted ---
map_msgs/ProjectedMapsInfo
map_msgs/SaveMap
map_msgs/SetMapProjections
midterm/WeatherStation <-------------
nav_msgs/GetMap
nav_msgs/GetPlan
nav_msgs/LoadMap
nav_msgs/SetMap
--- omitted ---
ros@ubuntu:~/catkin_ws/midterm$ rosrun midterm service_server
[ INFO] [1650766939.649994468]: Weather Station Server Running...
```
- Test the service in the new tab
```bash
ros@ubuntu:~/catkin_ws/midterm$ source devel/setup.bash
ros@ubuntu:~/catkin_ws/midterm$ rosservice list
/rosout/get_loggers
/rosout/set_logger_level
/weather_station <-------------
/weather_station_server_node/get_loggers
/weather_station_server_node/set_logger_level
ros@ubuntu:~/catkin_ws/midterm$ rosservice call /weather_station Seoul
weather_type: "sunny"
ros@ubuntu:~/catkin_ws/midterm$ rosservice call /weather_station Istanbul
weather_type: "cloudy"
ros@ubuntu:~/catkin_ws/midterm$ rosservice call /weather_station Sydney
weather_type: "windy"
ros@ubuntu:~/catkin_ws/midterm$ rosrun midterm service_client 
Type 'exit' to quit
Enter Location: Istanbul
The weather is cloudy
Enter Location: Seoul
The weather is sunny
Enter Location: Sydney
The weather is windy
Enter Location: Siberia
The weather is stormy
Enter Location: London
The weather is rainy
Enter Location: exit
[ INFO] [1650767144.709564698]: Exiting Application...
ros@ubuntu:~/catkin_ws/midterm$ 
```
### Task #2
- Raunch speed_check_simulator.launch
  - speed_limit is pre-defined (70 km/h) and can not be modified```
```bash
ros@ubuntu:~/catkin_ws/midterm$ source devel/setup.bash
ros@ubuntu:~/catkin_ws/midterm$ roslaunch midterm speed_check_simulator.launch 
... logging to /home/ros/.ros/log/c198ccb2-c374-11ec-b91c-974d1a0c2498/roslaunch-ubuntu-75746.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://ubuntu:44113/

SUMMARY
========

PARAMETERS
 * /plate_number: 1234.0
 * /rosdistro: noetic
 * /rosversion: 1.15.14
 * /speed: 50.0

NODES
  /
    speed_check_node1 (midterm/speed_check)
    speed_limit_node1 (midterm/speed_limit)

ROS_MASTER_URI=http://localhost:11311

process[speed_limit_node1-1]: started with pid [75760]
process[speed_check_node1-2]: started with pid [75761]
```
- Test changing speed 
  - ```bash plate_number``` is pre-defined (1234) and can be modified by ```bash rosparam set plate_number <new_value>```
  - ```bash speed``` is pre-defined (50 km/h) and can be modified by ```bash rosparam set speed <new_value>```
```bash
os@ubuntu:~/catkin_ws/midterm$ rosparam list
/plate_number <-------------
/rosdistro
/roslaunch/uris/host_ubuntu__33377
/roslaunch/uris/host_ubuntu__44113
/rosversion
/run_id
/speed <-------------
ros@ubuntu:~/catkin_ws/midterm$ rosparam dump
plate_number: 1234.0 <-------------
rosdistro: 'noetic

  '
roslaunch:
  uris:
    host_ubuntu__33377: http://ubuntu:33377/
    host_ubuntu__44113: http://ubuntu:44113/
rosversion: '1.15.14

  '
run_id: c198ccb2-c374-11ec-b91c-974d1a0c2498
speed: 50.0 <-------------
ros@ubuntu:~/catkin_ws/midterm$ rostopic list
/rosout
/rosout_agg
/speed <-------------
/speed_limit <-------------
ros@ubuntu:~/catkin_ws/midterm$ 
```
  - Initially there will not be any output as the ```bash speed``` does not exceed the ```speed_limit```
```bash
ros@ubuntu:~/catkin_ws/midterm$ rostopic echo speed
_
```
  - Increase ```speed``` that exceeds ```speed_limit``` (higher than 70) in a new tab
  ```bash 
  -  and the ```plate_number``` will be printed
 ```bash
 ros@ubuntu:~/catkin_ws/midterm$ rosparam set speed 75
 ros@ubuntu:~/catkin_ws/midterm$
 ```
 ros@ubuntu:~/catkin_ws/midterm$ rostopic echo speed_limit
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ---
 data: 1234.0
 ...
 ```
