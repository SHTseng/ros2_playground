#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "path_viz_interface/srv/plan_path.hpp"

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr rcl_node = rclcpp::Node::make_shared("path_planner_client");
    auto client = rcl_node->create_client<path_viz_interface::srv::PlanPath>("plan_path");
    auto request = std::make_shared<path_viz_interface::srv::PlanPath::Request>();
    geometry_msgs::msg::PoseStamped pose;
    pose.header.frame_id = "odom";
    pose.pose.position.x = 0.0;
    pose.pose.position.y = 0.0;
    pose.pose.position.z = 0.0;
    pose.pose.orientation = geometry_msgs::msg::Quaternion();
    request->start_pose = pose;
    pose.pose.position.x = 100.0;
    pose.pose.position.y = 100.0;
    pose.pose.position.z = 0.0;
    pose.pose.orientation = geometry_msgs::msg::Quaternion();
    request->goal_pose = pose;

    while(!client->wait_for_service(1s))
    {
        if(!rclcpp::ok())
        {
            RCLCPP_ERROR(rcl_node->get_logger(), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rcl_node->get_logger(), "service not available, waiting again...");
    }

    auto result = client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(rcl_node, result) != rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_ERROR(rcl_node->get_logger(), "Did not get a valid path result.");
    }

    auto path = result.get();
    (void)path;
    rclcpp::shutdown();
}