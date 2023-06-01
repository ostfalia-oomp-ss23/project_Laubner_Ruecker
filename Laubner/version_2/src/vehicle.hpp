#pragma once

#include <string>
#include <iostream>

class Vehicle
{
public:
    void readVehicle();
    void printVehicle();

    std::string mBrand;
    std::string mModel;
    int mYear;
};

