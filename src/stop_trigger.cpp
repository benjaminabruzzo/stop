#include <ros/ros.h>
#include <std_msgs/Bool.h>

	std_msgs::Bool STOP_msg;

	int main(int argc, char **argv)
	{
		ros::init(argc, argv, "STOP");
		ros::NodeHandle n;
		/*-----  Publishers and Subscribers */

		std::string s_stop_topic;
		if(ros::param::get("~stop_topic",s_stop_topic)){} else {s_stop_topic = "/stop/shutdown";}
		ros::Publisher STOP		= n.advertise<std_msgs::Bool>(s_stop_topic, 1000);

		while (ros::ok())
		{
			ROS_INFO("Ready to stop ROS nodes.\n");
			STOP_msg.data = true;
			std::cin.ignore();
			ROS_INFO("Stopping ROS nodes...");
			for(int b = 1; b < 15; ++b)
			{
				STOP.publish(STOP_msg);
				ros::spinOnce();
				ros::Duration(0.1).sleep(); // sleep for 'x' second(s).
			}

			ROS_INFO("Resetting Stopswitch...");
			for(int b = 1; b < 15; ++b)
			{
				STOP_msg.data = false;
				STOP.publish(STOP_msg);
				ros::spinOnce();
				ros::Duration(0.1).sleep(); // sleep for 'x' second(s).
			}
			ROS_INFO("...done\n");
			ros::shutdown();
		}

		return 0;
	}
