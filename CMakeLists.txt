# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set project name
project(MyProject)

# Add flags and configurations
set(CMAKE_CXX_STANDARD 23) # Set C++ standard to 17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-deprecated") # Enable compiler warnings

# Add subdirectory
add_subdirectory(Arrays arrays) 
add_subdirectory(Classes classes)
add_subdirectory(File_handling file_handling) 
add_subdirectory(Linked_list linkedlist) 
add_subdirectory(Queue queue) 
add_subdirectory(Random random) 
add_subdirectory(Stack stack) 
add_subdirectory(Strings strings) 
add_subdirectory(Tree tree) 
add_subdirectory(lambdas Lambdas)  
add_subdirectory(Stl Stl) 






