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
    std::cout << "DroneControllerPlugin is Loading..." << std::endl;
    // Store the pointer to the model and world
    this->model = _parent;
    this->world = this->model->GetWorld();
    std::cout << "DroneControllerPlugin has loaded." << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Called by the world update start event
  void OnUpdate()
  {
  }

private:

  /// \brief Pointer to the model.
  physics::ModelPtr model;

  /// \brief World from the model.
  physics::WorldPtr world;
};

// Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(DroneControllerPlugin)
} // namespace gazebo