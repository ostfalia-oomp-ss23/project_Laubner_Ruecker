#include <string>
#include <list>
#include "vehicle.h"
#include <fstream>
#ifndef specialVehicle_h
#define specialVehicle_h

class SpecialVehicle : public Vehicle
{

public:
int Number = 0;
int mLength, mHight, mWidth;
std::string mAddition;

SpecialVehicle();
SpecialVehicle(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, int mLength, int mHight, int mWidth, std::string &mAddition);
~SpecialVehicle(); 

static SpecialVehicle addspecVehicle(int Size);
void printVehicle() override;
};
#endif