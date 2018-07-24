#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>

visualization_msgs::Marker marker;


void vehiclepose(const geometry_msgs::PoseStamped &posestamped)
   {
     marker.pose.position.x = posestamped.pose.position.x;       
     marker.pose.position.y = posestamped.pose.position.y;
     marker.pose.position.z = posestamped.pose.position.z+10;
   }



int main(int argc, char** argv)
 {
    ros::init(argc, argv, "liuchen_rviz_marker");
    ros::NodeHandle n;
    ros::Rate r(1);

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);
    ros::Subscriber sub = n.subscribe("/poseidon_0/localization/pose", 1, vehiclepose);

     
    uint32_t shape = marker.SPHERE;


    while (ros::ok())
    {
      marker.header.frame_id = "/world";
      marker.header.stamp = ros::Time::now();
  
      marker.ns = "liuchen_rviz_marker";
      marker.id = 0;
      marker.type = shape;
      marker.action = visualization_msgs::Marker::ADD;
  
      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;
  
      marker.scale.x = 1.0;
      marker.scale.y = 1.0;
      marker.scale.z = 1.0;

      marker.color.r = 0.0f;
      marker.color.g = 1.0f;
      marker.color.b = 0.0f;
      marker.color.a = 1.0f;

      marker.lifetime = ros::Duration();

      //while (marker_pub.getNumSubscribers() < 1)
        //{
          //if (!ros::ok())
           //{
             //return 0;
           //}
          //ROS_WARN_ONCE("Please create a subscriber to the marker");
          sleep(1);
        //}
      marker_pub.publish(marker);
      ros::spinOnce();
    }
    return 0;
  }
