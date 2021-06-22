cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cloud_viewer)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (cloud_viewer src/cloud_viewer.cpp)
target_link_libraries (cloud_viewer ${PCL_LIBRARIES})


add_executable (txt2pcl src/txt2pcl.cpp)
target_link_libraries (txt2pcl ${PCL_LIBRARIES})

add_executable (icp src/icp.cpp)
target_link_libraries (icp ${PCL_LIBRARIES})
