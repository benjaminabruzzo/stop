# Installation
	mkdir -p ~/ros/src/stop && cd ~/ros/src/stop && git init
	git remote add gh git@github.com:benjaminabruzzo/stop.git
	git pull gh master && cd ~/ros && catkin build stop
