#pragma once
#include <iostream>

#define STANDARD_STRING_LENGTH 64

class Vehicle 
{

public:

    void read();
    void print();

    std::string brand;
    std::string model;
    int year;
};