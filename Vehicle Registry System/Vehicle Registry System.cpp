#include <iostream>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer, model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    ~Vehicle() {}

    void setVehicleID(int id) { vehicleID = id; }
    int getVehicleID() { return vehicleID; }

    void inputVehicle()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
        totalVehicles++;
    }

    void displayVehicle()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

// Single Inheritance
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void inputCar()
    {
        inputVehicle();
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void displayCar()
    {
        displayVehicle();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    void inputElectricCar()
    {
        inputCar();
        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }

    void displayElectricCar()
    {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// Multiple Inheritance
class Aircraft
{
protected:
    int flightRange;

public:
    void inputAircraft()
    {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }

    void displayAircraft()
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    void inputFlyingCar()
    {
        inputCar();
        inputAircraft();
    }

    void displayFlyingCar()
    {
        displayCar();
        displayAircraft();
    }
};

// Multilevel Inheritance
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    void inputSportsCar()
    {
        inputElectricCar();
        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }

    void displaySportsCar()
    {
        displayElectricCar();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// Hierarchical Inheritance
class Sedan : public Car
{
};

class SUV : public Car
{
};

class VehicleRegistry
{
private:
    Car car[10];
    ElectricCar electricCar[10];
    FlyingCar flyingCar[10];
    SportsCar sportsCar[10];
    Sedan sedan[10];
    SUV suv[10];

    int c = 0, e = 0, f = 0, s = 0, sd = 0, su = 0;

public:
    void addVehicle()
    {
        int type;

        cout << "\n1. Car";
        cout << "\n2. Electric Car";
        cout << "\n3. Flying Car";
        cout << "\n4. Sports Car";
        cout << "\n5. Sedan";
        cout << "\n6. SUV";
        cout << "\nEnter Vehicle Type: ";
        cin >> type;

        if (type == 1)
            car[c++].inputCar();
        else if (type == 2)
            electricCar[e++].inputElectricCar();
        else if (type == 3)
            flyingCar[f++].inputFlyingCar();
        else if (type == 4)
            sportsCar[s++].inputSportsCar();
        else if (type == 5)
            sedan[sd++].inputCar();
        else if (type == 6)
            suv[su++].inputCar();
        else
            cout << "Invalid Type!" << endl;

        cout << "Vehicle Added Successfully!" << endl;
    }

    void displayAll()
    {
        for (int i = 0; i < c; i++)
        {
            cout << "\nCar " << i + 1 << endl;
            car[i].displayCar();
        }

        for (int i = 0; i < e; i++)
        {
            cout << "\nElectric Car " << i + 1 << endl;
            electricCar[i].displayElectricCar();
        }

        for (int i = 0; i < f; i++)
        {
            cout << "\nFlying Car " << i + 1 << endl;
            flyingCar[i].displayFlyingCar();
        }

        for (int i = 0; i < s; i++)
        {
            cout << "\nSports Car " << i + 1 << endl;
            sportsCar[i].displaySportsCar();
        }

        for (int i = 0; i < sd; i++)
        {
            cout << "\nSedan " << i + 1 << endl;
            sedan[i].displayCar();
        }

        for (int i = 0; i < su; i++)
        {
            cout << "\nSUV " << i + 1 << endl;
            suv[i].displayCar();
        }

        cout << "\nTotal Vehicles: " << Vehicle::totalVehicles << endl;
    }

    void searchVehicle()
    {
        int id, found = 0;

        cout << "Enter Vehicle ID: ";
        cin >> id;

        for (int i = 0; i < c; i++)
            if (car[i].getVehicleID() == id)
            {
                car[i].displayCar();
                found = 1;
            }

        for (int i = 0; i < e; i++)
            if (electricCar[i].getVehicleID() == id)
            {
                electricCar[i].displayElectricCar();
                found = 1;
            }

        for (int i = 0; i < f; i++)
            if (flyingCar[i].getVehicleID() == id)
            {
                flyingCar[i].displayFlyingCar();
                found = 1;
            }

        for (int i = 0; i < s; i++)
            if (sportsCar[i].getVehicleID() == id)
            {
                sportsCar[i].displaySportsCar();
                found = 1;
            }

        for (int i = 0; i < sd; i++)
            if (sedan[i].getVehicleID() == id)
            {
                sedan[i].displayCar();
                found = 1;
            }

        for (int i = 0; i < su; i++)
            if (suv[i].getVehicleID() == id)
            {
                suv[i].displayCar();
                found = 1;
            }

        if (found == 0)
            cout << "Vehicle Not Found!" << endl;
    }
};

int main()
{
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n===== Vehicle Registry System =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search By ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vr.addVehicle();
            break;

        case 2:
            vr.displayAll();
            break;

        case 3:
            vr.searchVehicle();
            break;

        case 4:
            cout << "Thank You!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}