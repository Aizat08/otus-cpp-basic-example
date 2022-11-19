cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(Forward_container Forward_container.cpp)
set_target_properties(Forward_container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(Linked_list Linked_list.cpp)
set_target_properties(Linked_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)