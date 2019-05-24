#!/bin/sh
# Plugin Compile
if [ ! -d "./build" ]; then mkdir build; fi
 cd build && 
 cmake ../ && 
 make &&

# Setup
export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH &&
echo  'GAZEBO_PLUGIN_PATH =' $GAZEBO_PLUGIN_PATH
cd .. &&
export GAZEBO_MODEL_PATH=`pwd`/models/:$GAZEBO_MODEL_PATH
echo 'GAZEBO_MODEL_PATH = ' $GAZEBO_MODEL_PATH

# Run
 gazebo -u --verbose ./drone_simulation.world