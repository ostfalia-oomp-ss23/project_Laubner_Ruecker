#include <iostream>
#include <vector>
#include <array>
#include "vehicle.h"

#define NUMBER_OF_VEHICLES 32

bool wantToReadAnotherVehicle(){
    char answer;
    std::cout << "Do you want to insert another vehicle? [y/n] " << std::endl;
    std::cin >> answer;
    return answer == 'y';
}


int main(int argc, char* argv[]){
    std::cout << "Rental Company Example started!" << std::endl;
    std::array <Vehicle,NUMBER_OF_VEHICLES> array_of_vehicles;
    int id = 0;
    do{
        array_of_vehicles[id].read();
        id++;
    }while(wantToReadAnotherVehicle());

    std::cout << "Ausgabe der Fahrzeugliste\n" << std::endl;

    for(int j=0; j<id; j++){
        array_of_vehicles[j].print();
    };
    std::cout << "Rental Company Example finished!" << std::endl;
    return 0;
};
