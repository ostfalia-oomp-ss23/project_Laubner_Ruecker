#pragma once
#include <iostream>

#define STANDARD_STRING_LENGTH 64

class Vehicle 
{
private:
    

public:

    void read();
    void print();

    int mileage;
    std::string brand;
    std::string model;
    int year;

};