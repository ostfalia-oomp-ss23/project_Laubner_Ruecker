#include "vehicle.hpp"

void Vehicle::readVehicle()
{
    std::cout << "Brand: " << std::endl;
    std::cin >> mBrand;
    std::cout << "\n";

    std::cout << "Model: " << std::endl;
    std::cin >> mModel;
    std::cout << "\n";

    std::cout << "Year: " << std::endl;
    std::cin >> mYear;
    std::cout << "\n";
}

void Vehicle::printVehicle()
{
    std::cout << "Brand:\t" << mBrand << "\n";
    std::cout << "Model:\t" << mModel << "\n";
    std::cout << "Year:\t" << mYear << "\n";
}