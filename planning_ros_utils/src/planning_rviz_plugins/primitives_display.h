#include <boost/circular_buffer.hpp>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>
#include <rviz/visualization_manager.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/bool_property.h>
#include <rviz/frame_manager.h>

#include <rviz/load_resource.h>

#include <planning_ros_msgs/Primitives.h>
#include <rviz/message_filter_display.h>

#include "primitive_visual.h"

namespace planning_rviz_plugins {
  class PrimitivesDisplay
    : public rviz::MessageFilterDisplay<planning_ros_msgs::Primitives> {
      Q_OBJECT
      public:
        PrimitivesDisplay();
        virtual ~PrimitivesDisplay();

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
        void updateHistoryLength();
        void updateNum();

      private:
        void processMessage(const planning_ros_msgs::Primitives::ConstPtr &msg);
        void visualizeMessage();

        boost::circular_buffer<boost::shared_ptr<PrimitiveVisual>> visuals_;

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
        rviz::IntProperty *history_length_property_;
        rviz::IntProperty *num_property_;

        Ogre::Vector3 position_;
        Ogre::Quaternion orientation_;

        planning_ros_msgs::Primitives prs_msg_;
    };

}
