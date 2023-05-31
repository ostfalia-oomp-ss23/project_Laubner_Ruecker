#include "vehicle.h"
#include "time.h"

//Reader---------------------------------------------------------------------------Reader 
Vehicle Vehicle::readVehicle()
{

	// Temp Variablen
	std::string brand;
	std::string model;
	int year;

	// Abfrage der Marke
	std::cin.ignore();
	std::cout << "Brand:\n\r";
	std::getline (std::cin, brand);

	// Abfrge des Modells
	std::cout << "Model:\n\r";
	std::getline (std::cin, model);

	// Abfrage des Baujahres
	std::cout << "Year:\n\r";
	std::cin >> year;

	// Aufruf des Konstruktors & return
	return (Vehicle(brand, model, year));

}
int Vehicle::readHUdays()
{
	int HUDays, Day, Month, Year;
	int DaysDiff = 913;
	char delimiter = '.';
	
	while (DaysDiff >= 912)
	{
		std::cout << "Hauptuntersuchung:[tt.mm.yyyy]\n\r";
		std::cin >> Day >> delimiter >> Month >> delimiter >> Year;
		HUDays = Day + (Month * 30) + (Year * 365);
		DaysDiff = HUDays - (*GetTime() +((*(GetTime() + 1) * 30)) + ((*(GetTime() + 2) * 365)));
		//std::cout << DaysDiff << " | "<< HUDays;
		if (DaysDiff >= 912)
		{
			std::cout << "Das Datum ist zu weit in der Zukunft!\n\r";
		}
	}
	return HUDays;
}
int Vehicle::readMileage()
{
	int mileage = 0;
	while (!mileage > getmMileage())
	{
		std::cout << "Bitte geben sie den aktuellen Kilometerstand an:\n\r";
		std::cin >> mileage;
	}
	return mileage;
}
int Vehicle::readID() const
{
	std::cout << "------------------------------------------------\n\r";
	int id = 0;
	getNewID();
	std::cout << "Geben Sie die ID des Fahrzeuges an![ID]\n\r";
	std::cin.ignore();
	std::cin >> id;
	return id;
}
//Printer-----------------------------------------------------------------------------Printer
void Vehicle::print() const
{
	// Ausgabe des Eintrages
	std::cout << "Vehicle-ID: " << mID << "\t|"<< "Brand:\t\t"<< mBrand << "\n\t\t|Model:\t\t" << mModel << "\n\t\t|Year:\t\t" << mYear << "\n\t\t|Mileage:\t" << mMileage << "\n\t\t|HU-Datum:\t" << getmInspection() << "\n\r";

}
// Setter-----------------------------------------------------------------------------Setter
void Vehicle::setInspectionDate(int HUDays)
{
	mInstpectionDate = HUDays;
}
void Vehicle::setMileage(int mile)
{
	mMileage = mile;
}
void Vehicle::setID(int ID)
{
	mID = ID;
}
// Getter-------------------------------------------------------------------------------Getter
std::string Vehicle::getmBrand() const
{
	return mBrand;
}
std::string Vehicle::getmModel() const
{
	return mModel;
}
int Vehicle::getmYear() const
{
	return mYear;
}
int Vehicle::getmMileage() const
{
	return mMileage;
}
std::string Vehicle::getmInspection() const
{
	int YearR = (mInstpectionDate % 365);
	int Year = (mInstpectionDate / 365);
	int Month = ceil((YearR / 30));
	int Day = ceil((YearR % 30));
	if (Month == 0)
	{
		 Month++;
	}
	if (Day == 0)
	{
		Day++;
	}
	
	std::stringstream ss;
	ss << Day << "." << Month << "." << Year;
	std::string Inspectionstr(ss.str());

	return Inspectionstr;
}

int Vehicle::getID() const
{
	return mID; 
}

int Vehicle::getNewID() const
{
	std::string a,b,c,d,e;
	int NewID = 0;
	std::ifstream datei("AutoList.csv");
	std::string SearchID;

	if(!datei.is_open())
	{
		std::cerr << "Failed zo open file!\n\r";
	}
	else
	{
		while(getline(datei, SearchID))
		{	
			for (size_t i = 0; i < (SearchID.length()/4); i++)
			{
				if (SearchID[i] == ',')
				{
					SearchID[i] = ' ';
				}
			}
			std::stringstream sss(SearchID);
			sss >> NewID;
			sss.str("");
		} 
		std::cout << "Vorhandene Fahrzeuge: " << NewID << "\n\r";
		datei.close();
	} 
	NewID++;
	return NewID;
}