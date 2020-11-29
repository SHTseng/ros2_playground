cmake_minimum_required(VERSION 3.5)
project(path_viz)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(path_viz_interface REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(path_viz_server src/viz_service.cpp)
ament_target_dependencies(path_viz_server rclcpp path_viz_interface std_msgs visualization_msgs nav_msgs)
install(TARGETS path_viz_server
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()