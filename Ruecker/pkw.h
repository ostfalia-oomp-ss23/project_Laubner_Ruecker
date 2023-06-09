#include <string>
#include "vehicle.h"
#include <list>
#include <fstream>
#ifndef pkw_h
#define pkw_h
class PKW : public Vehicle
{

public:
int Number = 0;
int  mSeats;
std::string mFuel, mPlaque;

PKW(); //Leerer konstruktor für Funktionsaufruf in vehicle Manager
PKW(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, const int nSeats, const std::string &Fuel, const std::string &Plaque);
~PKW();


static PKW addPKW(int Size);
void printVehicle() override;


};
#endif