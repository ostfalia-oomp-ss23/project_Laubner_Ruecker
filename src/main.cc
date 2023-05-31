#include "vehicle.h"
#include "vehicleManager.h"
#include <iostream>


bool wantToReadAnotherVehicle()
{
    char answer;
    std::cout << "Do you want to insert another vehicle? [y/n]" << std::endl;
    std::cin >> answer;
    return answer == 'y';
}

int main(int argc, char* argv[])
{
    int id;
	VehicleManager * choose;
	int Vchoose;
	do 
	{
		 Vchoose = choose->Menu();

		switch (Vchoose)
		{
			case 1:
				// Fahrzeug einlesen und speichern
				do
				{
					// Fahrzeug Anlegen(konst Variablen)
					Vehicle TempVehicle = Vehicle::readVehicle();
					// Nicht const Variablen anlegen
					TempVehicle.setInspectionDate(TempVehicle.readHUdays());

					TempVehicle.setMileage(TempVehicle.readMileage());
					// ID für das Vehicle bestimmen
					TempVehicle.setID(TempVehicle.getNewID());
					// Eingegebenes Fahrzeug ausgeben
					TempVehicle.print();
					// Fahrzeug ausgeben
					choose->WriteVehicle(TempVehicle);
					// Abfrage zur weiteren Eingabe
				} while (wantToReadAnotherVehicle());
			break;

			case 2:
				// Fin Fahrezug ausgeben
				do
				{	
					Vehicle * TempRead;
					choose->ReadVehicle(TempRead->readID());
				} while (wantToReadAnotherVehicle());
			break;

			case 3:
			// Alle Fahrzeuge ausgeben
				choose->ReadAllVehicles();
			break;

			case 4:
			// Fahrzeug modifizieren
				do
				{	
					Vehicle * TempRead;
					choose->modVehicle(TempRead->readID());

				} while (wantToReadAnotherVehicle());
			break;
			
			case 5:
			// Fahrzeug entfernen
				Vehicle * TempRead;
				choose->delVehicle(TempRead->readID());

			break;

			case 6:
				// Program wird beendet!
				std::cout << "Programm wird beendet!\n\r";
				return 0;
				
			default:
				Vchoose = 0;
				std::cout << "Bitte prüfen sie ob ihre eingabe korrekt ist!\n\r";
		}
	}while (!(Vchoose == 6));
}