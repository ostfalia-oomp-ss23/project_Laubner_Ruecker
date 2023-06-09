#include <iostream>
#include <vector>
#include <array>
#include "vehicle.h"
#include "vehicleManager.h"
#include <list>
#define NUMBER_OF_VEHICLES 32



int main(int argc, char* argv[]) {
    
    std::cout << "Willkommen in deiner neuen Fahrzeugkartei: \n\r" << std::endl;
    
    VehicleManager Testauswahl(1);
    while (1)
    {
        Testauswahl.choseFunction(1);
    }
    return 0;
}