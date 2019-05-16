mkdir build
cd build
cmake ../
make
export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH
echo '************************************************************'
echo 'Press keys: 6, y, h, u, j, i, k'
echo '************************************************************'
gazebo -u --verbose ../simple_arm_teleop.world