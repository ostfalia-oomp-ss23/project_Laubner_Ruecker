#include "vehicle.h"
#include <iostream>

 void Vehicle::read() {
            std::cout << "Brand: " << std::endl;
            std::cin >> brand;
            std::cout << "Model: " << std::endl;
            std::cin >> model;
            std::cout << "Year: " << std::endl;
            std::cin >> year;
            };
void Vehicle::print(){
            std::cout << "Brand: " << brand << std::endl;
    	    std::cout << "Model: " << model << std::endl;
            std::cout << "Year: " << year << std::endl;
        }