#include <iterator>
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

#include <vector>
#include <eigen3/Eigen/Dense>
#include <cmath>

#include "ros/ros.h"

class ekf {
  public:
    ekf() {
      float x = 0.0;
      float y = 0.0;
      float theta = 0.0;
      pose_curr << x, y, theta;
      calc_trigger = false;
    }

    Eigen::Vector3f pose_next;
    Eigen::Vector3f pose_curr;
    void odom_callback(const nav_msgs::Odometry msg);

  private:

}; 

void ekf::odom_callback(const nav_msgs::Odometry msg) { 

    // sanity test to ensure we can see twist in this node:
    ROS_INFO("twist_linear_x: [%f]", msg.twist.twist.linear.x);
    ROS_INFO("twist_linear_y: [%f]", msg.twist.twist.linear.y);
    ROS_INFO("twist_angular: [%f]", msg.twist.twist.angular.z);

    float linear_x =  msg.twist.twist.linear.x;
    float linear_y =  msg.twist.twist.linear.y;
    float angular_z =  msg.twist.twist.angular.z;

    Eigen::Vector3f current_velocity;
    current_velocity << linear_x, linear_y, angular_z;

    Eigen::Vector3f motion_model;

}

int main(int argc, char **argv)
{

  ekf ekf_;
  ros::init(argc, argv, "ekf_impl");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("odom", 1, &ekf::odom_callback, &ekf_);
  ros::spin();

  return 0;
}
