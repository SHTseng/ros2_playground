from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node

def generate_launch_description():
    path_viz_service = Node(package='path_viz',executable='path_viz', name='path_viz', output='screen')
    rviz_cmd = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen')

    ld = LaunchDescription()
    ld.add_action(path_viz_service)
    ld.add_action(rviz_cmd)
    return ld