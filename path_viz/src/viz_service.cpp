#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/Marker.hpp"
// #include "visualization_msgs/msg/MarkerArray.hpp"
#include "nav_msgs/msg/Path.hpp"

#include <memory>
#include <vector>

class PathListener : public rclcpp::Node
{
public:
  explicit PathListener()
  : Node("path_listener")
  {
    sub_ = create_subscription<nav_msgs::msg::Path>("/path", 10, [this](const nav_msgs::msg::Path::SharedPtr msg)
    {
      // RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg->data.c_str());
      // pub_->publish(*msg);
    });
    pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/path_marker", 10);
  }

private:
  std::vector<visualization_msgs::msg::Marker> pathToMarker(const nav_msgs::msg::Path::SharedPtr msg)
  {
    return {};
  }

  rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr sub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr pub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PathListener>());
  rclcpp::shutdown();
  return 0;
}