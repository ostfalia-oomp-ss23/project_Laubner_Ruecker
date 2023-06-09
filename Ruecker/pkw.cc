#include <iostream>
#include "pkw.h"
#include <sstream>
#include <fstream>

    //public:
//Konstruktor für pkw anlegen
//PKW::PKW() {};

    PKW::PKW(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, const int nSeats, const std::string &Fuel, const std::string &Plaque) 
    : Vehicle(type, Number, brand, model, year, mileage, nextHU), mSeats(nSeats), mFuel(Fuel), mPlaque(Plaque)
{ 
    //std::cout << "Klasse PKW wurde geöffnet! \n\r" <<std::endl;
}
PKW::~PKW(){}

PKW PKW::addPKW(int Size)
{
    int  Number, Year, Mileage, nextHU, nSeats;
    std::string type, Brand, Model, Fuel, Plaque; 
    type = "PKW";
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
    std::cout << "Number of Seats: " <<std::endl;
    std::cin >> nSeats;
    std::cout << "Kind of Fuel: " <<std::endl;
    std::cin >> Fuel;
    std::cout << "Color of plaque: " <<std::endl;
    std::cin >> Plaque;

    PKW newPKW(type, Number, Brand, Model, Year, Mileage, nextHU, nSeats, Fuel, Plaque);
    return newPKW;
}

void PKW::printVehicle(){
    Vehicle::printVehicle();
    std::cout << "Seats: " << mSeats << "\n";
    std::cout << "Fuel: " << mFuel << "\n";
    std::cout << "Plaque: " << mPlaque << "\n" << std::endl;
}