#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <iostream>
namespace gazebo
{
class DroneControllerPlugin : public ModelPlugin
{
public:
  /////////////////////////////////////////////////////////////////////////////
  DroneControllerPlugin() {}

  /////////////////////////////////////////////////////////////////////////////
  ~DroneControllerPlugin() {}

  /////////////////////////////////////////////////////////////////////////////
  void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
  {
  }

  /////////////////////////////////////////////////////////////////////////////
  // Called by the world update start event
  void OnUpdate()
  {
  }

};

// Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(DroneControllerPlugin)
} // namespace gazebo