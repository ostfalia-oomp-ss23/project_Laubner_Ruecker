#include <iostream>
#include "vehicle.h"
#include "vehicleManager.h"
#include "pkw.h"

//unsigned int Vehicle::mNumberOfVehicles = 0;

// Vehicle::Vehicle(const std::string &brand, const std::string &model, const int year) : mBrand(brand), mModel(model), mYear(year)
// {
//     //std::cout << "Test Construktor 1" << std::endl;
// }

Vehicle::Vehicle(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU) 
: mType(type), mNumber(Number), mBrand(brand), mModel(model), mYear(year), mMileage(mileage), mNextHU(nextHU)
{
    //std::cout << "Test Construktor 2" << std::endl;
}
Vehicle::~Vehicle() {}

// Zugriffsfunktionen
std::string Vehicle::getType() const
{
    return mType;
}
std::string Vehicle::getBrand() const
{
    return mBrand;
}
std::string Vehicle::getModel() const
{
    return mModel;
}
int Vehicle::getYear() const
{
    return mYear;
}
int Vehicle::getMileage()
{
    return mMileage;
}
int Vehicle::getNextHU()
{
    return mNextHU;
}
int Vehicle::getNumber()
{
    return mNumber;
}

int Vehicle::setMileage(int nMileage)
{
    if (nMileage > mMileage)
    {
        mMileage = nMileage;
    }
    else
    {
        std::cout << "Error new mileage cant be less then old mileage! \n\r" << std::endl;
    }
    return 0;
}

int Vehicle::setNextHU(int nNextHU)
{
    if(0 < nNextHU && nNextHU < (912)) 
    {
        mNextHU = nNextHU;
    } else {
        std::cout << "Error time till next HU cant be longer than 912 Day (2.5Years) \n\r" << std::endl;
    }
    return mNextHU;
}
int Vehicle::setNumber(int nNumber)
{
    mNumber = nNumber;
    return mNumber;
}

void Vehicle::printVehicle(){
    std::cout<<"Nr: "<< mNumber << "\n";
    std::cout<<"Brand: "<< mBrand << "\n";
    std::cout<<"Model: "<< mModel << "\n";
    std::cout<<"Year: "<< mYear	 << "\n";
    std::cout<<"HU: "<< mNextHU << "\n"; 
    std::cout<<"Mileage: "<< mMileage << "\n";
}