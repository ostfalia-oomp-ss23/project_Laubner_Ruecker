#include <iostream>
#include "vehicleManager.h"
#include <sstream>
#include <fstream>

// Managerfunktionen
VehicleManager::VehicleManager(int Auswahl) : Choice(Auswahl)
{
    //std::cout << "Test Vehicle MANAGER" << std::endl;
    mInput.open("../Fahrzeugsammlung.csv");
    std::string line = "";
    // int Number = 0; // Setze Fahrzeugzähler auf 0!
    if (mInput.is_open())
    {
        std::getline(mInput, line); // Kopfzeile nicht beachten!
        line = "";

        while (std::getline(mInput, line))
        {
            std::string Type, Number, Brand, Model, Year, Mileage, NextHU, nSeats, Fuel, Plaque, Length, Hight, Width, maxPayload, nAxels, Addition;
            Number = "0";
            Year = "0";
            Mileage = "0";
            NextHU = "0";
            nSeats = "0";
            Hight = "0";
            Width = "0";
            maxPayload = "0";
            nAxels = "0";
            Length = "0";

            std::stringstream inPutLine(line);
            std::getline(inPutLine, Type, ';');
            std::getline(inPutLine, Number, ';');
            std::getline(inPutLine, Brand, ';');
            std::getline(inPutLine, Model, ';');
            std::getline(inPutLine, Year, ';');
            std::getline(inPutLine, Mileage, ';');
            std::getline(inPutLine, NextHU, ';');
            std::getline(inPutLine, nSeats, ';');
            std::getline(inPutLine, Fuel, ';');
            std::getline(inPutLine, Plaque, ';');
            std::getline(inPutLine, Length, ';');
            std::getline(inPutLine, Hight, ';');
            std::getline(inPutLine, Width, ';');
            std::getline(inPutLine, maxPayload, ';');
            std::getline(inPutLine, nAxels, ';');
            std::getline(inPutLine, Addition, '\n');
            // Number = Number +1;
            // Vehicle currentVehicle(Type, stoi(Number), Brand, Model, stoi(Year), stoi(Mileage), stoi(NextHU));
            if (Type == "PKW")
            {

                PKW newPKW(Type, stoi(Number), Brand, Model, stoi(Year), stoi(Mileage), stoi(NextHU), stoi(nSeats), Fuel, Plaque);
                pkwList.push_back(newPKW);
            }
            if (Type == "LKW")
            {
                LKW newLKW(Type, stoi(Number), Brand, Model, stoi(Year), stoi(Mileage), stoi(NextHU), stoi(Length), stoi(Hight), stoi(Width), stoi(maxPayload), stoi(nAxels));
                lkwList.push_back(newLKW);
            }
            if (Type == "SV")
            {
                SpecialVehicle newSpecialVehicle(Type, stoi(Number), Brand, Model, stoi(Year), stoi(Mileage), stoi(NextHU), stoi(Length), stoi(Hight), stoi(Width), Addition);
                specList.push_back(newSpecialVehicle);
            }
            // vehicleList.push_back(currentVehicle);
            //  std::cout << "Größe: " << Number << std::endl;
            line = "";
        }
        mInput.close();
    }
    else
    {
        std::cout << "File not found \n\r" << std::endl;
        exit(-1);
    }
}
VehicleManager::~VehicleManager() {}

void VehicleManager::SaveProgress()
{
    mOutput.open("../Fahrzeugsammlung.csv");
    if (mOutput.is_open())
    {
        // Write data
        mOutput << "Type"
                << ";"
                << "Number"
                << ";"
                << "Brand"
                << ";"
                << "Model"
                << ";"
                << "Year"
                << ";"
                << "Mileage"
                << ";"
                << "NextHU"
                << ";"
                << "Seats"
                << ";"
                << "Fuel"
                << ";"
                << "Plaque"
                << ";"
                << "Length"
                << ";"
                << "Hight"
                << ";"
                << "Width"
                << ";"
                << "maxPayload"
                << ";"
                << "Axels"
                << ";"
                << "Addition"
                << "\n";
        for (auto i : pkwList)
        {
            mOutput << i.getType() << ";"
                    << i.getNumber() << ";"
                    << i.getBrand() << ";"
                    << i.getModel() << ";"
                    << i.getYear() << ";"
                    << i.getMileage() << ";"
                    << i.getNextHU() << ";"
                    << i.mSeats << ";"
                    << i.mFuel << ";"
                    << i.mPlaque << ";;;;;;\n";
        }
        std::cout << "Vehicles succesfully saved in PKWList\n";
        for (auto i : lkwList)
        {
            mOutput << i.getType() << ";"
                    << i.getNumber() << ";"
                    << i.getBrand() << ";"
                    << i.getModel() << ";"
                    << i.getYear() << ";"
                    << i.getMileage() << ";"
                    << i.getNextHU() << ";;;;"
                    << i.mLength << ";"
                    << i.mHight << ";"
                    << i.mWidth << ";"
                    << i.mPayload << ";"
                    << i.mAxel << ";\n";
        }
        for (auto i : specList)
        {
            mOutput << i.getType() << ";"
                    << i.getNumber() << ";"
                    << i.getBrand() << ";"
                    << i.getModel() << ";"
                    << i.getYear() << ";"
                    << i.getMileage() << ";"
                    << i.getNextHU() << ";;;;"
                    << i.mLength << ";"
                    << i.mHight << ";"
                    << i.mWidth << ";;;"
                    << i.mAddition << "\n";
        }
    }
    else
    {
        std::cout << "failed to open Fahrzeugsammlung.csv \n";
    }
    mOutput.close();
}

void VehicleManager::addVehicle()
{
    std::string Type, Brand, Model;
    Number = vehicleList.size();
    int Year, Mileage, nextHU, xChoice;
    std::cout << "Um welche Art von Fahrzeug handelt es sich?\n\r";
    std::cout << "1. PKW \n\r";
    std::cout << "2. LKW \n\r";
    std::cout << "3. Sonderfahrzeug \n\r";
    std::cout << "4. zurück zum Menü \n\r" << std::endl;

    std::cin >> xChoice;

    // Number = Number +1;
    // std::cout << "Brand: " << std::endl;
    // std::cin >> Brand;
    // std::cout << "Model: " << std::endl;
    // std::cin >> Model;
    // std::cout << "Year: " << std::endl;
    // std::cin >> Year;
    // std::cout << "Mileage: " << std::endl;
    // std::cin >> Mileage;
    // std::cout << "Next HU: " << std::endl;
    // std::cin >> nextHU;

    // Vehicle newAuto(Number, Brand, Model, Year, Mileage, nextHU);
    switch (xChoice)
    {
    case 1:
    {
        // Type = "PKW";
        PKW myPKW = PKW::addPKW(pkwList.size());
        pkwList.push_back(myPKW);
        printVehicleList();
        break;
    }

    case 2:
    {
        // Type = "LKW";
        LKW myLKW = LKW::addLKW(lkwList.size());
        lkwList.push_back(myLKW);
        printVehicleList();
        break;
    }
    case 3:
    {
        // Type = "SV";
        SpecialVehicle myspecialVehicle = SpecialVehicle::addspecVehicle(specList.size());
        specList.push_back(myspecialVehicle);
        break;
    }
    default:
        std::cout << "!!!!!ALARM!!!! \n\r" << std::endl;
        break;
    }
    // vehicleList.push_back(newAuto);
}
void VehicleManager::deleteVehicle()
{
    int delNumber, Number, Choice;
    std::cout << "Welchen fahrzeugtyp möchten sie löschen?\n\r";
    std::cout << "1. PKW \n\r";
    std::cout << "2. LKW \n\r";
    std::cout << "3. Sonderfahrzeug \n\r";
    std::cin >> Choice;
    std::cout << "Welche Nr. soll gelöscht werden? " << std::endl;
    std::cin >> delNumber;
    Number = delNumber;
    delNumber = delNumber - 1;

    // LastNumber = vehicleList
    switch (Choice)
    {
    case 1:
    {
        if (delNumber < pkwList.size())
        {
            // Element löschen
            auto it = pkwList.begin();
            std::advance(it, delNumber);
            pkwList.erase(it);

            // Folgeelement neu nummerieren
            while (delNumber < pkwList.size())
            {
                auto obj = pkwList.begin();
                std::advance(obj, delNumber);
                obj->setNumber(Number);
                Number++;
                delNumber++;
            }
        }
        else
        {
            std::cout << "Ungültige Eingabe, zurück zum Menü \n\r" << std::endl;
        }
        break;
    }

    case 2:
    {
        if (delNumber < lkwList.size())
        {
            // Element löschen
            auto it = lkwList.begin();
            std::advance(it, delNumber);
            lkwList.erase(it);

            // Folgeelement neu nummerieren
            while (delNumber < lkwList.size())
            {
                auto obj = lkwList.begin();
                std::advance(obj, delNumber);
                obj->setNumber(Number);
                Number++;
                delNumber++;
            }
        }
        else
        {
            std::cout << "Ungültige Eingabe, zurück zum Menü \n\r" << std::endl;
        }
        break;
    }

    case 3:
    {
        if (delNumber < specList.size())
        {
            // Element löschen
            auto it = specList.begin();
            std::advance(it, delNumber);
            specList.erase(it);

            // Folgeelement neu nummerieren
            while (delNumber < specList.size())
            {
                auto obj = specList.begin();
                std::advance(obj, delNumber);
                obj->setNumber(Number);
                Number++;
                delNumber++;
            }
        }

    default:
        break;
    }
    }
}

void VehicleManager::modVehicle()
{
    std::string Brand, Model, ModChoice;
    Number = vehicleList.size();
    int ModNumber, Modification, Year, Mileage, nextHU, Choice;
    std::cout << "Welchen Fahrzeugtyp möchten sie bearbeiten?\n\r";
    std::cout << "1. PKW \n\r";
    std::cout << "2. LKW \n\r";
    std::cout << "3. Sonderfahrzeug \n\r";
    std::cin >> Choice;
    std::cout << "Welche Nr. soll bearbeitet werden? \n\r" << std::endl;
    std::cin >> ModNumber;
    ModNumber = ModNumber - 1;
    switch (Choice)
    {
    case 1:
        if (ModNumber < pkwList.size())
        {
            auto obj = pkwList.begin();
            std::advance(obj, ModNumber);
            // Bisheriges Fahrzeug anzeigen
            obj->printVehicle();
            // Abfrage Modifikation:
            std::cout << "Kilometerstand ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Neuer Kilometerstand: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setMileage(Modification);
            }
            std::cout << "Tage bis zur nächsten HU ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Tage bis zur HU: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setNextHU(Modification);
            }
            std::cout << "Bearbeitung abgeschlossen! \n\r \n\r" << std::endl;
            obj->printVehicle();
        }
        else
        {
            std::cout << "Ungültige Eingabe! \n\r" << std::endl;
        }
        break;
    case 2:
        if (ModNumber < lkwList.size())
        {
            auto obj = lkwList.begin();
            std::advance(obj, ModNumber);
            // Bisheriges Fahrzeug anzeigen
            obj->printVehicle();
            // Abfrage Modifikation:
            std::cout << "Kilometerstand ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Neuer Kilometerstand: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setMileage(Modification);
            }
            std::cout << "Tage bis zur nächsten HU ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Tage bis zur HU: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setNextHU(Modification);
            }
            std::cout << "Bearbeitung abgeschlossen! \n\r \n\r" << std::endl;
            obj->printVehicle();
        }
        else
        {
            std::cout << "Ungültige Eingabe! \n\r" << std::endl;
        }
        break;
    case 3:
        if (ModNumber < specList.size())
        {
            auto obj = specList.begin();
            std::advance(obj, ModNumber);
            // Bisheriges Fahrzeug anzeigen
            obj->printVehicle();
            // Abfrage Modifikation:
            std::cout << "Kilometerstand ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Neuer Kilometerstand: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setMileage(Modification);
            }
            std::cout << "Tage bis zur nächsten HU ändern? [y/n] \n\r" << std::endl;
            std::cin >> ModChoice;
            if (ModChoice == "y")
            {
                std::cout << "Tage bis zur HU: \n\r" << std::endl;
                std::cin >> Modification;
                obj->setNextHU(Modification);
            }
            std::cout << "Bearbeitung abgeschlossen! \n\r \n\r" << std::endl;
            obj->printVehicle();
        }
        else
        {
            std::cout << "Ungültige Eingabe! \n\r" << std::endl;
        }
        break;

    default:
        break;
    }
}

void VehicleManager::printVehicleList()
{
    std::cout << "PKW-Liste: \n\r";
    std::cout << "##################################\n\r" << std::endl;
    for (auto i : pkwList)
    {
        i.printVehicle(); // Warum wird hier das i nicht hochgezählt? oder geschieht das automatisch?????????????????
    }
    std::cout << "LKW-Liste: \n\r";
    std::cout << "##################################\n\r" << std::endl;
    for (auto i : lkwList)
    {
        i.printVehicle();
    }

    std::cout << "Spezialfahrzeuge-Liste: \n\r";
    std::cout << "##################################\n\r" << std::endl;
    for (auto i : specList)
    {
        i.printVehicle();
    }
}

void VehicleManager::choseFunction(int Choice)
{
    std::cout << "Menü: \n\r";
    std::cout << "1. Fahrzeug hinzufügen \n\r";
    std::cout << "2. Fahrzeuge ausgeben \n\r";
    std::cout << "3. Fahrzeug entfernen \n\r";
    std::cout << "4. Fahrzeug modifizieren \n\r";
    std::cout << "5. Save Progress \n\r";
    std::cout << "6. Program beenden \n\r" << std::endl;

    std::cin >> Choice;
    switch (Choice)
    {
    case 1:
        addVehicle();
        break;
    case 2:
        printVehicleList();
        break;
    case 3:
        deleteVehicle();
        break;
    case 4:
        modVehicle();
        break;
    case 5:
        SaveProgress();
        break;
    case 6:
        exitProgram();
        break;
    default:
        break;
    }
}

void VehicleManager::exitProgram()
{
    std::cout << "Program herunterfahren! \n\r" << std::endl;
    exit(1);
}