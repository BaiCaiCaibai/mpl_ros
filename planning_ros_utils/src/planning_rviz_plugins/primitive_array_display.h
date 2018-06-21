#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreSceneNode.h>
#include <rviz/frame_manager.h>
#include <rviz/properties/bool_property.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/visualization_manager.h>

#include <rviz/load_resource.h>

#include <planning_ros_msgs/PrimitiveArray.h>
#include <rviz/message_filter_display.h>

#include "primitive_visual.h"

namespace planning_rviz_plugins {
class PrimitiveArrayDisplay
    : public rviz::MessageFilterDisplay<planning_ros_msgs::PrimitiveArray> {
  Q_OBJECT
public:
  PrimitiveArrayDisplay();
  virtual ~PrimitiveArrayDisplay();

protected:
  virtual void onInitialize();

  virtual void reset();

private Q_SLOTS:
  void updatePosColorAndAlpha();
  void updateVelColorAndAlpha();
  void updateAccColorAndAlpha();
  void updateJrkColorAndAlpha();
  void updatePosScale();
  void updateVelScale();
  void updateAccScale();
  void updateJrkScale();
  void updateVelVis();
  void updateAccVis();
  void updateJrkVis();
  void updateNum();

private:
  void processMessage(const planning_ros_msgs::PrimitiveArray::ConstPtr &msg);
  void visualizeMessage();

  std::shared_ptr<PrimitiveVisual> visual_;

  rviz::ColorProperty *pos_color_property_;
  rviz::ColorProperty *vel_color_property_;
  rviz::ColorProperty *acc_color_property_;
  rviz::ColorProperty *jrk_color_property_;
  rviz::FloatProperty *pos_scale_property_;
  rviz::FloatProperty *vel_scale_property_;
  rviz::FloatProperty *acc_scale_property_;
  rviz::FloatProperty *jrk_scale_property_;
  rviz::BoolProperty *vel_vis_property_;
  rviz::BoolProperty *acc_vis_property_;
  rviz::BoolProperty *jrk_vis_property_;
  rviz::IntProperty *num_property_;

  Ogre::Vector3 position_;
  Ogre::Quaternion orientation_;

  planning_ros_msgs::PrimitiveArray prs_msg_;
};
}
