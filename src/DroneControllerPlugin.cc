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

    // Initialize keyboard transport
    this->node = transport::NodePtr(new transport::Node());
    this->node->Init();

    this->keyboardSub =
        this->node->Subscribe("~/keyboard/keypress",
                              &DroneControllerPlugin::OnKeyPress, this, true);

    std::cout << "DroneControllerPlugin has loaded." << std::endl;
  }

  void OnKeyPress(ConstAnyPtr &_msg)
  {
    char key = static_cast<char>(_msg->int_value());

    std::cout << "Button pressed." << std::endl;
    std::cout << key << std::endl;

  }

  /////////////////////////////////////////////////////////////////////////////
  // Called by the world update start event
  void OnUpdate()
  {
  }

private:
  /// \brief Node for communication.
  transport::NodePtr node;

  /// \brief Subscribe to keyboard messages.
  transport::SubscriberPtr keyboardSub;

  /// \brief Pointer to the model.
  physics::ModelPtr model;

  /// \brief World from the model.
  physics::WorldPtr world;
};

// Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(DroneControllerPlugin)
} // namespace gazebo