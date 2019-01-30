#include <ros/ros.h>
#include <std_msgs/Bool.h>

class stop_listener
{
	private:
		ros::Subscriber ShutDown_sub;

	public:
		ros::NodeHandle n;
		std::string s_stop_topic;

	stop_listener()
	{
		/*--------- Initialize ROS Communication & Variables ------------- */
		/*-----  Publishers and Subscribers */

		if(ros::param::get("~stop_topic",s_stop_topic)){} else {s_stop_topic = "/stop/shutdown";}
		ShutDown_sub= n.subscribe(s_stop_topic,   10,  &stop_listener::nodeShutDown, this);
		ROS_INFO("Shutdown Listener Constructed");
	}

	void nodeShutDown(const std_msgs::Bool::ConstPtr& ShutDown)
	{
		if(ShutDown->data)
			{ros::shutdown();}
	}

};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "stop_listener");
	stop_listener sL;
	ros::spin();
	return 0;
}
