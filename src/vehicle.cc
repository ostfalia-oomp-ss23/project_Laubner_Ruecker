#include "vehicle.h"
#include <iostream>
#include <string>

void Vehicle::read() 
{
    std::cout << "Brand: " << std::endl;
    std::getline(std::cin, brand);
         
    std::cout << "Model: " << std::endl;
    std::getline(std::cin, model);

    std::cout << "Year: " << std::endl;
    std::cin >> year;
}

void Vehicle::print()
 {
    std::cout << "\tbrand=" << brand << std::endl;
    std::cout << "\tmodel=" << model << std::endl;
    std::cout << "\tyear=" << year << std::endl;
}