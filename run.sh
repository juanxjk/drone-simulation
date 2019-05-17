mkdir build
cd build
cmake ../
make
export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH
cd ..
cp -r ./models/quad_2292_1/ ~/.gazebo/models/
gazebo -u --verbose ./drone_simulation.world
