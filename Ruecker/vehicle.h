#include <string> 
#ifndef vehicle_h
#define vehicle_h


class Vehicle
{

protected:
    const std::string mBrand;
    const std::string mModel;
    const std::string mType;
    const int mYear;
    int mMileage;
    int mNextHU;
    int mNumber;

public:
    //Vehicle(const std::string& brand, const std::string& model, const int year);

    Vehicle(const std::string& type, const int Number, const std::string& brand, const std::string& model, const int year, int mileage, int nextHU);
    ~Vehicle();

    std::string getBrand() const;
    std::string getModel() const;
    std::string getType() const;
    int getYear() const;
    int getMileage();
    int getNextHU();
    int getNumber();
    

    int setMileage(int nMileage);
    int setNextHU(int nNextHU);
    int setNumber(int nNumber);
    virtual void printVehicle();

    // void read() const;
    // void print();
};

#endif 