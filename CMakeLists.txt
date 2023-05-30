cmake_minimum_required(VERSION 3.1.0)

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
	src/vehicle.cc
	src/vehicle.h
	src/main.cc
)