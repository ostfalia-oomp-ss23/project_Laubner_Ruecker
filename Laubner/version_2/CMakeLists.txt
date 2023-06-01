cmake_minimum_required(VERSION 3.22.1)

set(TARGET_NAME cpp_project_vehicle_rental)

project(${TARGET_NAME})

#
# set cmake settings
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#
# add source files to target
#
add_executable(${TARGET_NAME}
	src/vehicle.cpp
	src/vehicle.hpp
	src/main.cpp
)
