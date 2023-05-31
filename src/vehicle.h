#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>


#ifndef VEHICLE_HPP
#define VEHICLE_HPP

bool wantToReadAnotherVehicle();

class Vehicle
{

	private:
	
		const std::string mBrand;
		const std::string mModel;
		const int mYear;
		int mID;
		int mMileage;
		int mInstpectionDate; // Gespeichert in tagen seit 1970
		
	public:
		// Funtion zum erstellen eines Fahrzeugs
		static Vehicle readVehicle();

		// Ausgabe des Temporär gepeicherten Vehicles
		void print() const;

		// Funtionen zum Abfagen des Weiteren Parameter
		int readHUdays();
		int readMileage();
		int readID() const;

		// Setter
		void setMileage(int mile);
		void setInspectionDate(int HUDays);
		void setID(int ID);

		// Getter
		std::string getmBrand() const;
		std::string getmModel() const;
		std::string getmInspection() const;
		int getmYear() const;
		int getmMileage() const;
		int getNewID() const;
		int getID() const;

		// Konstruktor
		Vehicle(const std::string &brand, const std::string &model, const int &year):
			mBrand(brand), mModel(model), mYear(year), mMileage(0), mInstpectionDate(0){std::cout << "ktor\n\r";}
			
		// Destruktor
		~Vehicle(){std::cout << "dtor\n\r";}
};
#endif