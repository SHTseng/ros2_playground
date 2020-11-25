#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "path_viz_interface/msg/num.hpp"
#include "path_viz_interface/srv/plot_path.hpp"

void handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<AddTwoInts::Request> request,
    const std::shared_ptr<AddTwoInts::Response> response)
{
    response->sum = request->a + request->b + request->c;
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr rcl_node = rclcpp::Node::make_shared("minimal_service");
    // RCLCPP_INFO("service start to spin");
    auto server = rcl_node->create_service<PlotPath>("PlotPath", handle_service);
    rclcpp::spin(rcl_node);
    rclcpp::shutdown();
}