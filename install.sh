#!/bin/bash

#INSTALLATION SCRIPT FOR pi_drone PROJECT

SOURCE_DIR=$(pwd)
cmake ./ -B ./build;
cd build/;
make;
if [ $? -eq 0 ];then

	if [ $EUID == "0" ];then
		cd $SOURCE_DIR
		ln -s $SOURCE_DIR/build/pi_drone /usr/bin/pi_drone
		systemctl link ./pidrn.service
		systemctl enable pidrn
		systemctl start pidrn
	elif [ $? -eq 0 ];then
		cd $SOURCE_DIR
		sudo ln -s $SOURCE_DIR/build/pi_drone /usr/bin/pi_drone
		sudo systemctl link ./pidrn.service
		sudo systemctl enable pidrn
		sudo systemctl start pidrn
	fi
fi
tput setaf 2; echo "Installation done!"
