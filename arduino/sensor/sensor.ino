/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

// Use the following line if you have a Leonardo or MKR1000
//#define USE_USBCON

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String temp_msg;
std_msgs::String humid_msg;
std_msgs::String moist_msg;
std_msgs::String ph_msg;
std_msgs::String ec_msg;
ros::Publisher temperature("temperature", &temp_msg);
ros::Publisher humidity("humidity", &humid_msg);
ros::Publisher soil_moisture("soil_moisture", &moist_msg);
ros::Publisher ph("ph", &ph_msg);
ros::Publisher ec("ec", &ec_msg);

void setup()
{
  nh.initNode();
  nh.advertise(temperature);
  nh.advertise(humidity);
  nh.advertise(soil_moisture);
  nh.advertise(ph);
  nh.advertise(ec);
}

void loop()
{
  dtostrf(3.14, 8, 6, temp_msg.data);
  dtostrf(3.14, 8, 6, humid_msg.data);
  dtostrf(3.14, 8, 6, moist_msg.data);
  dtostrf(3.14, 8, 6, ph_msg.data);
  dtostrf(3.14, 8, 6, ec_msg.data);
  temperature.publish( &temp_msg);
  humidity.publish( &humid_msg);
  soil_moisture.publish( &moist_msg);
  ph.publish( &ph_msg);
  ec.publish( &ec_msg);
  nh.spinOnce();
  delay(1000);
}