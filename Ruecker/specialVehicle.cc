#include "specialVehicle.h"
#include <iostream>
#include <sstream>
#include <fstream>

SpecialVehicle::SpecialVehicle(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, int Length, int Hight, int Width, std::string &Addition) 
: Vehicle(type, Number, brand, model, year, mileage, nextHU), mLength(Length), mHight(Hight), mWidth(Width), mAddition(Addition)
{
        //std::cout << "Klasse special Vehicle wurde geöffnet! \n\r" <<std::endl;
}
SpecialVehicle::~SpecialVehicle() {}

SpecialVehicle SpecialVehicle::addspecVehicle(int Size)
{
    int  Number, Year, Mileage, nextHU, Length, Hight, Width;
    std::string type, Brand, Model, Addition; 
    type = "SV";
    Number = Size;
    Number = Number +1;

    // Allgemeine Infos einlesen
    std::cin.ignore(6,'\n');
    std::cout << "Brand: " << std::endl;
    std::getline(std::cin, Brand);
    std::cout << "Model: " << std::endl;
    std::getline(std::cin, Model);
    std::cout << "Year: " << std::endl;
    std::cin >> Year;
    std::cout << "Mileage: " << std::endl;
    std::cin >> Mileage;
    std::cout << "Next HU: " << std::endl;
    std::cin >> nextHU;

    // PKW spezifische Infos einlesen
    std::cout << "Vehicle Length: " <<std::endl;
    std::cin >> Length;
    std::cout << "Vehicle Hight: " <<std::endl;
    std::cin >> Hight;
    std::cout << "Vehicle Width: " <<std::endl;
    std::cin >> Width;
    std::cin.ignore(6,'\n');
    std::cout << "Description of Special Addition: " <<std::endl;
    std::getline(std::cin, Addition);

    SpecialVehicle newspecialVehicle(type, Number, Brand, Model, Year, Mileage, nextHU, Length, Hight, Width, Addition);
    return newspecialVehicle;
}

void SpecialVehicle::printVehicle() {
    Vehicle::printVehicle();
    std::cout << "Length: " << mLength << "\n";
    std::cout << "Hight: " << mHight << "\n";
    std::cout << "Width: " << mWidth << "\n";
    std::cout << "Description of special Addition " << mAddition << "\n" << std::endl;
}
