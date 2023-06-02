#include "vehicle.hpp"

Vehicle Vehicle::readVehicle()
{
    std::string brand;
    std::string model;
    int year;

    // Eingabe der Fahrzeugdaten
    std::cout << "Brand: " << std::endl;
    std::cin >> brand;
    std::cout << "\n";

    std::cout << "Model: " << std::endl;
    std::cin >> model;
    std::cout << "\n";

    std::cout << "Year: " << std::endl;
    std::cin >> year;
    std::cout << "\n";

    return Vehicle(brand, model, year);
}

void Vehicle::printVehicle()
{
    // Ausgabe der Fahrzeugdaten
    std::cout << "Brand:\t" << mBrand << "\n";
    std::cout << "Model:\t" << mModel << "\n";
    std::cout << "Year:\t" << mYear << "\n";
}

std::string Vehicle::get_mBrand() const
{
    // Getter für mBrand
    return mBrand;
}

std::string Vehicle::get_mModel() const
{
    // Getter für mModel
    return mModel;
}

int Vehicle::get_mYear() const
{
    // Getter für mYear
    return mYear;
}

int Vehicle::get_mMileage()
{
    // Getter für mMileage
    return mMileage;
}

int Vehicle::get_mNextinspection()
{
    // Getter für mNextInspection
    return mNextInspection;
}

void Vehicle::set_mMileage(int miles)
{
    // Setter für mMileage mit Validierung
    if (miles < 0)
    {
        mMileage = 0;
    }
    else
    {
        mMileage = miles;
    }
}

void Vehicle::set_mNextInspection(int days)
{
    // Setter für mNextInspection mit Validierung
    if (days > 730)
    {
        days = 730;
    }
    else
    {
        mNextInspection = days;
    }
}

Vehicle() : mBrand(""), mModel(""), mYear(0), mMileage(0), mNextInspection(730)
{
    // Default constructor with default values for member variables
}

