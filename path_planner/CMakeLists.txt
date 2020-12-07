cmake_minimum_required(VERSION 3.5)
project(path_planner)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(path_viz_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(path_planner_service src/path_planner_service.cpp)
ament_target_dependencies(path_planner_service rclcpp path_viz_interface geometry_msgs nav_msgs)
install(TARGETS path_planner_service
  DESTINATION lib/${PROJECT_NAME})

add_executable(path_planner_client src/path_planner_client.cpp)
ament_target_dependencies(path_planner_client rclcpp path_viz_interface geometry_msgs nav_msgs)
install(TARGETS path_planner_client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()