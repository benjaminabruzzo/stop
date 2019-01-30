# Installation
	mkdir -p ~/ros/src/stop && cd ~/ros/src/stop && git init
	git remote add gh git@github.com:westpoint-robotics/darknet-yolov3-ros.git 
	git pull gh master && cd ~/ros && catkin build stop
