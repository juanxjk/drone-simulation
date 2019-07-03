#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <iostream>
#include <ignition/math/Vector3.hh>

using ignition::math::Vector3d;
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

    // Listen to the update event. This event is broadcast every
    // simulation iteration.
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(
        std::bind(&DroneControllerPlugin::OnUpdate, this));

    std::cout << "DroneControllerPlugin has loaded." << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////
  void OnKeyPress(ConstAnyPtr &_msg)
  {
    char key = static_cast<char>(_msg->int_value());
    switch (key)
    {
    case 't': // Show Simulation Time
      std::cout << this->world->SimTime() << std::endl;
      break;
    case 'y': // Move up
      break;
    case 'h': // Move down
      break;
    case 'j': // Move left
      break;
    case 'l': // Move right
      break;
    case 'g': //RESET
      reset();
      break;
  }
    std::cout << "[DEBUG] Button pressed: " << key << std::endl;
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
  /// \brief Pointer to the update event connection.
  event::ConnectionPtr updateConnection;

  enum EnumMotors
  {
    MOTOR_FRONT = 3,
    MOTOR_LEFT = 0,
    MOTOR_RIGHT = 1,
    MOTOR_BACK = 2
  };

  /// \brief Thrust applied by drone.
  Vector3d thrusts[4];

  /////////////////////////////////////////////////////////////////////////////
  void reset()
  {
    thrusts[MOTOR_FRONT] = 0.0;
    thrusts[MOTOR_LEFT] = 0.0;
    thrusts[MOTOR_RIGHT] = 0.0;
    thrusts[MOTOR_BACK] = 0.0;
  }
};

// Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(DroneControllerPlugin)
} // namespace gazebo