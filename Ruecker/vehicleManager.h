#include <string>
#include <list>
#include "vehicle.h"
#include "pkw.h"
#include "lkw.h"
#include "specialVehicle.h"
#include <fstream>
#ifndef vehicleManager_h
#define vehicleManager_h
class VehicleManager
{

public:
int Choice;
int Number = 0;
std::ifstream mInput;
std::ofstream mOutput;

VehicleManager(int Choice);
~VehicleManager();
void SaveProgress();
void choseFunction(int Choice);
void addVehicle();
void printVehicleList();
void deleteVehicle();
void modVehicle();
void exitProgram();
std::list<Vehicle> vehicleList;
std::list<PKW> pkwList;
std::list<LKW> lkwList;
std::list<SpecialVehicle> specList;

};
#endif