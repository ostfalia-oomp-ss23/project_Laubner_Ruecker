#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "vehicle.h"
#include "time.h"


class VehicleManager
{
	private:

	public:

		int Menu() const;
		void WriteVehicle(Vehicle vehicle) const;
		void ReadVehicle(int id) const;
		void ReadAllVehicles() const;
		void delVehicle(int id);
		void modVehicle(int id);

};