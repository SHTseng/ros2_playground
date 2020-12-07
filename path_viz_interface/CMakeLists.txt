cmake_minimum_required(VERSION 3.5)
project(path_viz_interface)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(
  path_viz_interface
  "msg/Num.msg"
  "srv/PlotPath.srv"
  "srv/PlanPath.srv"
  DEPENDENCIES std_msgs geometry_msgs nav_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()