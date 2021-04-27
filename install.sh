#!/bin/bash

#INSTALLATION SCRIPT FOR pi_drone PROJECT

SOURCE_DIR=$(pwd)
cmake ./ -B ./build;
cd build/;
make;

if [ $EUID != "0" ];then
	sudo ln -s $SOURCE_DIR/build/pi_drone /usr/bin/pi_drone
	cd ..
	sudo systemctl link ./pidrn.service
	sudo systemctl enable pidrn
else
	ln -s $SOURCE_DIR/build/pi_drone /usr/bin/pi_drone
	cd ..
	systemctl link ./pidrn.service
	systemctl enable pidrn
fi

