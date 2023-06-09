#include <iostream>
#include "lkw.h"
#include <sstream>
#include <fstream>


LKW::LKW(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, const int Length, const int Hight, const int Width, const int Payload, const int Axel) 
: Vehicle(type, Number, brand, model, year, mileage, nextHU), mLength(Length), mHight(Hight), mWidth(Width), mPayload(Payload), mAxel(Axel)
{
   // std::cout << "Klasse LKW wurde geöffnet! \n\r" <<std::endl;
}
LKW::~LKW() {}

LKW LKW::addLKW(int Size)
{
    int  Number, Year, Mileage, nextHU, Length, Hight, Width, maxPayload, nAxel;
    std::string type, Brand, Model; 
    type = "LKW";
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
    std::cout << "Max Payload: " <<std::endl;
    std::cin >> maxPayload;
    std::cout << "Number of Axels: " <<std::endl;
    std::cin >> nAxel;

    LKW newLKW(type, Number, Brand, Model, Year, Mileage, nextHU, Length, Hight, Width, maxPayload, nAxel);
    return newLKW;
}

void LKW::printVehicle(){
    Vehicle::printVehicle();
    std::cout << "Length: " << mLength << "\n";
    std::cout << "Hight: " << mHight << "\n";
    std::cout << "Width: " << mWidth << "\n";
    std::cout << "Max Payload: " << mPayload << "\n";
    std::cout << "Number of Axels: " << mAxel << "\n" << std::endl;
}