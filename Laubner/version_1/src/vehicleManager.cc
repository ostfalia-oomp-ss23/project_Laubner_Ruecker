#include "vehicleManager.h"

int VehicleManager::Menu() const
{
	int Input = 0;
	do
	{	
		std::cout << "------------------------------------------------\n\r";
		std::cout << "1. Fahrzeug hinzufügen\n2. Ein Fahrzeug ausgeben[ID]\n3. Alle Fahrzeuge ausgeben\n4. Fahrzeug modifizieren\n5. Fahzeug entfernen\n6. Beenden\n\r";;
		std::cout << "------------------------------------------------\n\r";
		std::cout << "Wählen sie mit der jeweiligen zahl!\n\r";
		std::cin >> Input;
		std::cout << "\n\r";
		
	} while (!(Input == 1,2,3,4,5,6));
	return Input;
}

void VehicleManager::WriteVehicle(Vehicle TempVehicle) const
{
	// erstellen einer Datei
	std::string DataName("AutoList.csv");
	std::ofstream outfile;

	outfile.open(DataName, std::ios_base::app);
	if (!outfile.is_open())
	{
		std::cerr << "Failed to open File\n\r";
	}
	else
	{
		// Datei Header ertsellen
		if (TempVehicle.getID() == 1)
		{
			outfile << "ID,Marke,Model,Baujahr,Kilometerstand,HU-Datum" << std::endl;
		}
		outfile << TempVehicle.getID() << "," << TempVehicle.getmBrand() << "," << TempVehicle.getmModel() << "," << TempVehicle.getmYear() << ","<< TempVehicle.getmMileage() << "," << TempVehicle.getmInspection() << std::endl;
		outfile.close();
		std::cout << "Vehicle wurde Gespeichert!\n\r!";
	}
}

void VehicleManager::ReadVehicle(int id) const
{
	std::string a,b,c,d,e;
	int ID = 0;

	std::ifstream datei("AutoList.csv");
	std::string SearchID;


	if(!datei.is_open())
	{
		std::cerr << "Failed to open File\n\r";
	}
	else
	{
		
		// Zeile für Zeile auslesen
		while (getline(datei, SearchID) && ID != id)
		{
			for (size_t i = 0; i < SearchID.length(); i++)
			{
				if (SearchID[i] == ',')
				{
					SearchID[i] = ' ';
				}
			}
			std::stringstream Search(SearchID);
			Search >> ID >> a >> b >> c >> d >> e;
			Search.str("");
			
		}
		if (ID != id)
		{
			std::cout << "Fahrzeug wurde nicht gefunden\n\r";
		}
		else
		{
			std::cout << "Vehicle-ID: " << ID << "\t|Brand:\t\t"<< a << "\n\t\t|Model:\t\t" << b << "\n\t\t|Year:\t\t" << c << "\n\t\t|Mileage:\t" << d << "\n\t\t|HU-Datum:\t" << e << "\n\r";
			std::cout << "------------------------------------------------\n\r";
		}
	datei.close();
	}
}
void VehicleManager::ReadAllVehicles() const
{
	std::string a,b,c,d,e;
	char delimiter = ',';
	int ID = 0;

	std::ifstream datei("AutoList.csv");
	std::string SearchID;
	if(!datei.is_open())
	{
		std::cerr << "Failed to open File\n\r";
	}
	else
	{
		getline(datei, SearchID);
		while (getline(datei, SearchID))
		{
			for (size_t i = 0; i < SearchID.length(); i++)
			{
				if (SearchID[i] == ',')
				{
					SearchID[i] = ' ';
				}
			}
			std::stringstream Search(SearchID);
			Search >> ID >> a >> b >> c >> d >> e;
			Search.str("");
			std::cout << "Vehicle-ID: " << ID << "\t|Brand:\t\t"<< a << "\n\t\t|Model:\t\t" << b << "\n\t\t|Year:\t\t" << c << "\n\t\t|Mileage:\t" << d << "\n\t\t|HU-Datum:\t" << e << "\n\r";
			std::cout << "------------------------------------------------\n\r";
		}
		datei.close();
	}
	std::cout << "Ausgabe beendet!\n\r";
}
void VehicleManager::delVehicle(int id)
{
	// Variablen callen
	std::string a,b,c,d,e, filename;
	int ID = 0;
	filename = "AutoList.csv";
	std::string line;
	// Dateien öffnen
	std::fstream oldDatei(filename);
	std::ofstream newDatei("temp.csv");
	// Überprüfungs frage
	bool deleted = false;

	if(!oldDatei.is_open())
	{
		std::cerr << "Failed to open File\n\r";
	}
	else
	{
		while(getline(oldDatei, line))
		{
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
				{
					line[i] = ' ';
				}
			}
				std::stringstream SearchID(line);
				SearchID >> ID >> a >> b >> c >> d >> e;
				SearchID.str("");
			if (ID != id)
			{
				if(!newDatei.is_open())
				{
					std::cerr << "Failed to open File\n\r";
				}
				else
				{
					for (size_t i = 0; i < line.length(); i++)
					{
						if (line[i] == ' ')
						{
							line[i] = ',';
						}
					}
					newDatei << line << std::endl;
				}
			}
			else
			{
				deleted = true;
			}
		}
		oldDatei.close();
		newDatei.close();
		remove(filename.c_str());
		rename("temp.csv", filename.c_str());
	}
	if (deleted)
	{
		std::cout << "Fahrzeug erfolgreich gelöscht!\n\r";
	}
	else
	{
		std::cout << "Fahrzeug konnte nicht gelöscht werden\n\r";
	}
}
void VehicleManager::modVehicle(int id)
{
	char choice;
	//car variablen
	int ID = 0;
	int oldMileage, year, newMileage;
	std::string brand, model, inspectionDate, inspectionDate1;
	do
	{
		std::cout << "------------------------------------------------\n\r";
		std::cout << "Möchten Sie den Kilometerstand anpassen?[y/n]\n\r";
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 'y')
		{
			std::cout << "------------------------------------------------\n\r";
			std::cout << "Geben sie den neuen Kilometerstand ein\n\r";
			std::cin >> newMileage;

			// Datei öffnen
			int d, c;
			std::string a, b, e;
			std::string line;
			std::string filename = "AutoList.csv";
			std::fstream datei(filename);
			if (!(datei.is_open()))
			{
				std::cerr << "Failed to open File\n\r";
			}
			else
			{
				while (getline(datei, line))
				{
					for (size_t i = 0; i < line.length(); i++)
					{
						if (line[i] == ',')
						{
							line[i] = ' ';
						}
					}
					std::stringstream SearchID(line);
					SearchID >> ID >> a >> b >> c >> d >> e;
					if (ID == id)
					{
						brand = a;
						model = b;
						year = c;
						oldMileage = d;
						inspectionDate = e;
					}
					SearchID.str("");
				}
				datei.close();
			}
			if (oldMileage < newMileage)
			{
				std::cout << "in OldMileage > newMileage\n\r";
				// Dateien öffnen
				std::fstream oldDatei(filename);
				std::ofstream newDatei("temp.csv");

				if(!oldDatei.is_open())
				{
					std::cerr << "Failed to open File\n\r";
				}
				else
				{
					std::cout << "old Datei offen\n\r";
					while(getline(oldDatei, line))
					{
						for (size_t i = 0; i < line.length(); i++)
						{
							if (line[i] == ',')
							{
								line[i] = ' ';
							}
						}
							std::stringstream SearchID(line);
							SearchID >> ID >> a >> b >> c >> d >> e;
							SearchID.str("");
						if (ID != id)
						{
							if(!newDatei.is_open())
							{
								std::cerr << "Failed to open File\n\r";
							}
							else
							{
								std::cout << "nicht gesuchte fahrzeug newDatei offen\n\r";
								for (size_t i = 0; i < line.length(); i++)
								{
									if (line[i] == ' ')
									{
										line[i] = ',';
									}
								}
								newDatei << line << std::endl;
							}
						}
						else
						{	
							if(!newDatei.is_open())
							{
								std::cerr << "Failed to open File\n\r";
							}
							else
							{
							std::cout << "Fahrzeug wieder herstellen\n\r";
							// neue zeile einspielen
							std::stringstream newLine;
							newLine << id << "," << brand << "," << model << "," << year << "," << oldMileage << "," << inspectionDate << std::endl;
							newDatei << newLine.str();
							}
						}
					}
					// datein schließen, umbennen und löschen
					oldDatei.close();
					newDatei.close();
					remove(filename.c_str());
					rename("temp.csv", filename.c_str());
				}
			}
			else
			{
				std::cout << "Kilometerstand zu niedrig! Aktuellerstand:" << oldMileage << "\n\r";
				choice = 'q';
			}
		}
		else if( choice == 'n')
		{

		}
		else
		{
			std::cout << "Inkorrekte Eingabe!\n\r";
		}
	}while (!(choice == 'y' || choice == 'n'));
	
	do
	{

		std::cout << " Möchten Sie den das HU-Datum anpassen?[y/n]\n\r";
		std::cin.ignore();
		std::cin >> choice;
		if (choice == 'y')
		{
			std::cout << "Geben sie den neuen HU-Datum ein![tt.mm.yyyy]\n\r";
			std::cin >> inspectionDate;
			// Datei öffnen
			int d, c;
			std::string a, b, e;
			std::string line;
			std::string filename = "AutoList.csv";
			std::fstream datei(filename);
			if (!(datei.is_open()))
			{
				std::cerr << "Failed to open File\n\r";
			}
			else
			{
				while (getline(datei, line))
				{
					for (size_t i = 0; i < line.length(); i++)
					{
						if (line[i] == ',')
						{
							line[i] = ' ';
						}
					}
					std::stringstream SearchID(line);
					SearchID >> ID >> a >> b >> c >> d >> e;
					if (ID == id)
					{
						brand = a;
						model = b;
						year = c;
						oldMileage = d;
					}
					SearchID.str("");
				}
				datei.close();
			}
			
			for (size_t i = 0; i < inspectionDate1.length(); i++)
			{
				if (inspectionDate1[i] == '.')
				{
					inspectionDate1[i]= ' ';
				}
			}
			int day, m, y;
			std::stringstream ss(e);
			ss >> day >> m >> y;
			int HUDays = day + (m * 30) + (y * 365);
			int DaysDiff = HUDays - (*GetTime() +((*(GetTime() + 1) * 30)) + ((*(GetTime() + 2) * 365)));

			
			if ( DaysDiff <= 912)
			{
				// Dateien öffnen
				std::fstream oldDatei(filename);
				std::ofstream newDatei("temp.csv");
				// Überprüfungs frage
				bool changed = false;

				if(!oldDatei.is_open())
				{
					std::cerr << "Failed to open File\n\r";
				}
				else
				{
					while(getline(oldDatei, line))
					{
						for (size_t i = 0; i < line.length(); i++)
						{
							if (line[i] == ',')
							{
								line[i] = ' ';
							}
						}
							std::stringstream SearchID(line);
							SearchID >> ID >> a >> b >> c >> d >> e;
							SearchID.str("");
						if (ID != id)
						{
							if(!newDatei.is_open())
							{
								std::cerr << "Failed to open File\n\r";
							}
							else
							{
								for (size_t i = 0; i < line.length(); i++)
								{
									if (line[i] == ' ')
									{
										line[i] = ',';
									}
								}
								newDatei << line << std::endl;
							}
						}
						else
						{
							if(!newDatei.is_open())
							{
								std::cerr << "Failed to open File\n\r";
							}
							else
							{
							// neue zeile einspielen
							std::stringstream newLine;
							newLine << id << "," << brand << "," << model << "," << year << "," << oldMileage << "," << inspectionDate << std::endl;
							newDatei << newLine.str();
							}
						}
					}
					// datein schließen, umbennen und löschen.
					oldDatei.close();
					newDatei.close();
					remove(filename.c_str());
					rename("temp.csv", filename.c_str());
				}
			}
			else
			{
				std::cout << "HU-Datum zu weit in der Zukunft aktuelles Datum:" << e << "\n\r";
				choice = 'q';
			}
		}
		else
		{
			std::cout << "Inkorrekte Eingabe!\n\r";



		}


	} while (!(choice == 'y', 'n'));
}