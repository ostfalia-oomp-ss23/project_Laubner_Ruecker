#include "vehicle.hpp"

#include <map>

std::map<int, std::unique_ptr<Vehicle>> vehicleMap;

bool wantToReadAnotherVehicle()
{
    char answer;
    std::cout << "Wollen Sie ein weiteres Fahrzeug einlesen?[j/n]:" << std::endl;
    std::cin >> answer;
    std::cout << "\n";
    return answer == 'j';
}

int main(int argc, char const *argv[])
{
    std::cout << "-----Fahrzeug-Management wurde gestartet!-----\n" << std::endl;

    int id = 0;

    do
    {
        Vehicle vehicle = Vehicle::readVehicle();
        vehicleMap.emplace(id,vehicle);
        id++;
    } while (wantToReadAnotherVehicle());
    
    for (size_t i = 0; i < vehicleMap.size(); i++)
    {
        vehicleMap[i].printVehicle();
    }
    
    

    std::cout << "\n-----Programm wird beendet-----!" << std::endl;
    return 0;
}
