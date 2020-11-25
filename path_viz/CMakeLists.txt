cmake_minimum_required(VERSION 3.5)
project(path_viz)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
# find_package(example_interfaces REQUIRED)
find_package(path_viz_interface REQUIRED)
find_package(rclcpp REQUIRED)

rosidl_generate_interfaces(
  path_viz_interface
  "msg/Num.msg"
  "srv/PlotPath.srv")

add_executable(path_viz_service src/viz_service.cpp)
ament_target_dependencies(path_viz rclcpp path_viz_interface)
install(TARGETS path_viz
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()