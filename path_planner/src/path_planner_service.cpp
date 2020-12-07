#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "path_viz_interface/srv/plan_path.hpp"

static nav_msgs::msg::Path planPath(
    const geometry_msgs::msg::PoseStamped& start,
    const geometry_msgs::msg::PoseStamped& goal)
{
    nav_msgs::msg::Path path;
    // path.header.stamp = "odom";
    path.header.frame_id = "odom";
    path.poses.push_back(start);
    path.poses.push_back(goal);
    return path;
}

void handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header, // required?
    const std::shared_ptr<path_viz_interface::srv::PlanPath::Request> request,
    const std::shared_ptr<path_viz_interface::srv::PlanPath::Response> response)
{
    response->path = planPath(request->start_pose, request->goal_pose);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "path planned");
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr rcl_node = rclcpp::Node::make_shared("path_planner_service");

    auto server = rcl_node->create_service<path_viz_interface::srv::PlanPath>("plan_path", &handle_service);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Start path planning service.");

    rclcpp::spin(rcl_node);
    rclcpp::shutdown();
}