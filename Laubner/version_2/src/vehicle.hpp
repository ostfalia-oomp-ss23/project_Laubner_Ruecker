#pragma once

#include <string>
#include <iostream>

class Vehicle
{
private:
    std::string const mBrand; // Markenname des Fahrzeugs
    std::string const mModel; // Modellname des Fahrzeugs
    int const mYear; // Produktionsjahr des Fahrzeugs
    int mMileage; // Kilometerstand des Fahrzeugs
    int mNextInspection; // Tage bis zur nächsten Inspektion

public:
    Vehicle readVehicle(); // Funktion zum Einlesen von Fahrzeugdaten
    void printVehicle(); // Funktion zum Ausgeben von Fahrzeugdaten

    // Getter-Funktionen zum Abrufen der Werte der privaten Member-Variablen
    std::string get_mBrand() const;
    std::string get_mModel() const;
    int get_mYear() const;
    int get_mMileage();
    int get_mNextinspection();
    
    // Setter-Funktionen zum Aktualisieren der Werte der privaten Member-Variablen
    void set_mMileage(int miles);
    void set_mNextInspection(int days);

    Vehicle(const std::string &brand, const std::string &model, const int &year)
    : mBrand(brand), mModel(model), mYear(year), mMileage(0), mNextInspection(730)
    {
        // Konstruktor für die Initialisierung der Member-Variablen
    }

    ~Vehicle()
    {
        // Destruktor
    }

    Vehicle() : mBrand(""), mModel(""), mYear(0), mMileage(0), mNextInspection(730)
    {
        // Default constructor with default values for member variables
    }
};
