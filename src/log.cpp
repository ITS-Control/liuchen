vehicle_visualizer.py

  self.pub_scene_text = rospy.Publisher('/simulation/scene_text', MarkerArray, queue_size=1)
  marker_text_array = MarkerArray()
        for _id, vehicle in vehicles.iteritems():
            marker_text = self._get_general_marker(
                _id, Marker.TEXT_VIEW_FACING, vehicle)

            marker_text.pose.position.x = vehicle_state.pose.linear.x
            marker_text.pose.position.y = vehicle_state.pose.linear.y
            marker_text.pose.position.z = vehicle_state.pose.linear.z + 3

            marker_text.scale.x = 1.5
            marker_text.scale.y = 1.5
            marker_text.scale.z = 1.5

            marker_text.text = self._get_output_text(vehicles=vehicles,
                                                     self_id=_id,
                                                     focus_state=focus_state,
                                                     self_state=vehicle_state)
            marker_text.color.a = 1.0
            marker_text.color.r = 0.0
            marker_text.color.g = 1.0
            marker_text.color.b = 0.0

  marker_text_array.markers.append(marker_text)
  self.pub_scene_text.publish(marker_text_array)
  output_text = 'speed: {:.2f}m/s'.format(self_speed)

def _get_output_text(self, vehicles, self_id, focus_state, self_state):
      try:
            self_speed = int(math.sqrt(self_state.velocity.linear.x**2 + self_state.velocity.linear.y**2))
      except ValueError as e:
            rospy.logwarn(e)
            self_speed = 0.0

      output_text = 'speed: {:.2f}m/s'.format(self_speed)
      if self_id != 0:
            output_text += '\nto ego: {:.2f}m'.format(dist_to_focus)
      return output_text
  //在ROS WIKI中，visualization_msgs::Marker::Text
                  const char* text
                  
