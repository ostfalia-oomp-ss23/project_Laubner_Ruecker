#include "vehicle.h"
#include <iostream>
#define NUMBER_OF_VEHICLES 32

Vehicle vehicles[NUMBER_OF_VEHICLES];

bool wantToReadAnotherVehicle()
{
    char answer;
    std::cout << "Do you want to insert another vehicle? [y/n]" << std::endl;
    std::cin >> answer;
    return answer == 'y';
}

int main(int argc, char* argv[])
{
    std::cout << "Rental Company Example Started" << std::endl;
    
    int id = 0;
    
    do
    {
        Vehicle* vehicle = &vehicles[id];
        vehicle -> read();
        id++;
    } while (wantToReadAnotherVehicle());

    std::cout << std::endl;

    for(int i=0; i<id; i++)
    {
        Vehicle* vehicle = &vehicles[i];
        std::cout << "Vehicle id=" << i << std::endl;
        vehicle->print();
    }
    
    return 0;
}