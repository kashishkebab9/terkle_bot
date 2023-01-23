#include <iterator>
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>

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
    }

    Eigen::Vector2f cmd_vel;

    Eigen::Vector3f pose_next;
    Eigen::Vector3f pose_curr;
    void odom_callback(const nav_msgs::Odometry msg);
    void cmd_callback(const geometry_msgs::Twist msg);

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



}

void ekf::cmd_callback(const geometry_msgs::Twist msg) { 
  this->cmd_vel << msg.linear.x, msg.angular.z;

}
int main(int argc, char **argv)
{

  ekf ekf_;
  ros::init(argc, argv, "ekf_impl");
  ros::NodeHandle n;
  ros::Subscriber sub_odom = n.subscribe("odom", 1, &ekf::odom_callback, &ekf_);
  ros::Subscriber sub_cmd = n.subscribe("cmd_vel", 1, &ekf::cmd_callback, &ekf_);
  ros::spin();

  return 0;
}
