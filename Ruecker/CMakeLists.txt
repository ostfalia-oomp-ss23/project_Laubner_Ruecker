cmake_minimum_required(VERSION 3.1.0)

set(TARGET_NAME labor)

project(${TARGET_NAME})



add_executable(${TARGET_NAME}
	vehicle.cc
	vehicle.h
	vehicleManager.cc
	vehicleManager.h
	pkw.cc
	pkw.h
	lkw.cc
	lkw.h
	specialVehicle.cc
	specialVehicle.h
	main.cc
)