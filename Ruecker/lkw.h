#include <string>
#include <list>
#include "vehicle.h"
#include <fstream>
#ifndef lkw_h
#define lkw_h

class LKW : public Vehicle
{

public:
int Number = 0;
int mLength, mHight, mWidth, mPayload, mAxel;

LKW(); //Leerer konstruktor für Funktionsaufruf in vehicle Manager
LKW(const std::string &type, const int Number, const std::string &brand, const std::string &model, const int year, const int mileage, const int nextHU, const int Length, const int Hight, const int Width, const int Payload, const int Axel);
~LKW(); 

static LKW addLKW(int Size);
void printVehicle() override;
};
#endif