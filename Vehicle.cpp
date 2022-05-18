#include "Vehicle.hpp"

void CLEAR(void) //Clear screen regardles of host OS
{
    system("cls||clear");
    return;
}

Vehicle::Vehicle() //Constructor
{
    year = 0;
    manufacturer = "";
    model = "";
    color = "";
    vin = "";
    plate = "";
    weight = 0;
    engine = 0;
    power = 0;
    seats = 0;
}

Vehicle::Vehicle(int year, std::string manufacturer, std::string model, std::string color, std::string vin, std::string plate, int weight, int engine, int power, int seats) //Constructor with parameters
{
    this->year = year;
    this->manufacturer = manufacturer;
    this->model = model;
    this->color = color;
    this->vin = vin;
    this->plate = plate;
    this->weight = weight;
    this->engine = engine;
    this->power = power;
    this->seats = seats;
}

Vehicle::~Vehicle(){} //Destructor

//Getters start here

int Vehicle::getYear() //Get year
{
    return year;
}

std::string Vehicle::getManufacturer() //Get manufacturer
{
    return manufacturer;
}

std::string Vehicle::getModel() //Get model
{
    return model;
}

std::string Vehicle::getColor() //Get color
{
    return color;
}

std::string Vehicle::getVIN() //Get VIN
{
    return vin;
}   

std::string Vehicle::getPlate() //Get plate
{
    return plate;
}

int Vehicle::getWeight() //Get weight
{
    return weight;
}

int Vehicle::getEngine() //Get engine
{
    return engine;
}

int Vehicle::getPower() //Get power
{
    return power;
}

int Vehicle::getSeats() //Get seats
{
    return seats;
}

//Getters end here

//Setters start here

void Vehicle::setYear(int year) //Set year
{
    this->year = year;
}

void Vehicle::setManufacturer(std::string manufacturer) //Set manufacturer
{
    this->manufacturer = manufacturer;
}

void Vehicle::setModel(std::string model) //Set model
{
    this->model = model;
}

void Vehicle::setColor(std::string color) //Set color
{
    this->color = color;
}

void Vehicle::setVIN(std::string vin) //Set VIN
{
    this->vin = vin;
}

void Vehicle::setPlate(std::string plate) //Set plate
{
    this->plate = plate;
}

void Vehicle::setWeight(int weight) //Set weight
{
    this->weight = weight;
}

void Vehicle::setEngine(int engine) //Set engine
{
    this->engine = engine;
}

void Vehicle::setPower(int power) //Set power
{
    this->power = power;
}

void Vehicle::setSeats(int seats) //Set seats
{
    this->seats = seats;
}

//Setters end here

std::ostream& operator<< (std::ostream& os, Vehicle& v) //Overloaded output operator
{
    os << "\033[1;34m" << std::setw(4) << v.getYear() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(14) << v.getManufacturer() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(14) << v.getModel() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(20) << v.getColor() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(16) << v.getVIN() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(17) << v.getPlate() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(8) << v.getWeight() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(9) << v.getEngine() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(6) << v.getPower() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(10) << v.getSeats() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    return os;
}

std::istream& operator>> (std::istream& is, Vehicle& v) //Overloaded input operator
{
    is >> v.year;
    is >> v.manufacturer;
    is >> v.model;
    is >> v.color;
    is >> v.vin;
    is >> v.plate;
    is >> v.weight;
    is >> v.engine;
    is >> v.power;
    is >> v.seats;
    return is;
}

void Add(Vehicle vehicles[], int &n) //Add vehicle function
{
    int year, weight, engine, power, seats;
    std::string manufacturer, model, color, vin, plate;
    std::cout << "Introduceti datele noului autoturism: \n";
    std::cout << "Anul fabricatiei: "; std::cin >> year;
    std::cout << "Producator: "; std::cin >> manufacturer;
    std::cout << "Model: "; std::cin >> model;
    std::cout << "Culoare: "; std::cin >> color;
    std::cout << "VIN: "; std::cin >> vin;
    std::cout << "Placa: "; std::cin >> plate;
    std::cout << "Greutate: "; std::cin >> weight;
    std::cout << "Cilindree: "; std::cin >> engine;
    std::cout << "Putere: "; std::cin >> power;
    std::cout << "Locuri: "; std::cin >> seats;
    vehicles[n] = Vehicle(year, manufacturer, model, color, vin, plate, weight, engine, power, seats);
    n++;
}

void ModifyYear(Vehicle vehicles[], int n) //Modify year function
{
    int choice, year;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noul an fabricatiei: ";
        std::cin >> year;
        vehicles[choice - 1].setYear(year);
    }
}

void ModifyManufacturer(Vehicle vehicles[], int n) //Modify manufacturer function
{
    int choice;
    std::string manufacturer;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noul producator: ";
        std::cin >> manufacturer;
        vehicles[choice - 1].setManufacturer(manufacturer);
    }
}

void ModifyModel(Vehicle vehicles[], int n) //Modify model function
{
    int choice;
    std::string model;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noul model: ";
        std::cin >> model;
        vehicles[choice - 1].setModel(model);
    }
}

void ModifyColor(Vehicle vehicles[], int n) //Modify color function
{
    int choice;
    std::string color;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noua culoare: ";
        std::cin >> color;
        vehicles[choice - 1].setColor(color);
    }
}

void ModifyVIN(Vehicle vehicles[], int n) //Modify VIN function
{
    int choice;
    std::string vin;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noul VIN: ";
        std::cin >> vin;
        vehicles[choice - 1].setVIN(vin);
    }
}

void ModifyPlate(Vehicle vehicles[], int n) //Modify plate function
{
    int choice;
    std::string plate;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noua placa: ";
        std::cin >> plate;
        vehicles[choice - 1].setPlate(plate);
    }
}

void ModifyWeight(Vehicle vehicles[], int n) //Modify weight function
{
    int choice;
    int weight;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noua greutate: ";
        std::cin >> weight;
        vehicles[choice - 1].setWeight(weight);
    }
}

void ModifyEngine(Vehicle vehicles[], int n) //Modify engine function
{
    int choice;
    int engine;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noul tip motor: ";
        std::cin >> engine;
        vehicles[choice - 1].setEngine(engine);
    }
}

void ModifyPower(Vehicle vehicles[], int n) //Modify power function
{
    int choice;
    int power;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noua putere: ";
        std::cin >> power;
        vehicles[choice - 1].setPower(power);
    }
}

void ModifySeats(Vehicle vehicles[], int n) //Modify seats function
{
    int choice;
    int seats;
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        std::cout << "Introduceti noua numarul de locuri: ";
        std::cin >> seats;
        vehicles[choice - 1].setSeats(seats);
    }
}

void Print(Vehicle vehicles[], int n) //Print function
{
    char header[157] = "| ID |  An  |      Marca     |      Model     |        Culoare       |    Numar Sasiu    | Nr. Inmatriculare | Greutate | Cilindree | Putere | Nr. Locuri |";
    char spacer[157] = "|====|======|================|================|======================|===================|===================|==========|===========|========|============|";
    std::cout << "\033[1;35m" << spacer << std::endl << header << std::endl << spacer << std::endl << "\033[0m";
    for (int i = 0; i < n; i++)
    {
        std::cout << "\033[1;35m" << "| " << "\033[0m" << "\033[1;34m" << std::setw(2) << i+1 << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
        std::cout << vehicles[i] << '\n';
        std::cout << "\033[1;35m" << spacer << "\033[0m" << std::endl;
    }
}

void Modify(Vehicle vehicles[], int n) //Modify menu function
{
    int choice;
    Print(vehicles, n);
    std::cout << "1. Modify year" << std::endl;
    std::cout << "2. Modify manufacturer" << std::endl;
    std::cout << "3. Modify model" << std::endl;
    std::cout << "4. Modify color" << std::endl;
    std::cout << "5. Modify VIN" << std::endl;
    std::cout << "6. Modify plate" << std::endl;
    std::cout << "7. Modify weight" << std::endl;
    std::cout << "8. Modify engine" << std::endl;
    std::cout << "9. Modify power" << std::endl;
    std::cout << "10. Modify seats" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
        case 1:
            ModifyYear(vehicles, n);
            break;
        case 2:
            ModifyManufacturer(vehicles, n);
            break;
        case 3:
            ModifyModel(vehicles, n);
            break;
        case 4:
            ModifyColor(vehicles, n);
            break;
        case 5:
            ModifyVIN(vehicles, n);
            break;
        case 6:
            ModifyPlate(vehicles, n);
            break;
        case 7:
            ModifyWeight(vehicles, n);
            break;
        case 8:
            ModifyEngine(vehicles, n);
            break;
        case 9:
            ModifyPower(vehicles, n);
            break;
        case 10:
            ModifySeats(vehicles, n);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}

void Delete(Vehicle vehicles[], int &n) //Delete function
{
    int choice;
    Print(vehicles, n);
    std::cout << "Introduceti numarul autoturismului: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "Invalid choice" << std::endl;
    }
    else
    {
        for (int i = choice - 1; i < n - 1; i++)
        {
            vehicles[i] = vehicles[i + 1];
        }
        n--;
    }
}

void Search(Vehicle vehicles[], int n) //Search function
{
    char header[157] = "| ID |  An  |      Marca     |      Model     |        Culoare       |    Numar Sasiu    | Nr. Inmatriculare | Greutate | Cilindree | Putere | Nr. Locuri |";
    char spacer[157] = "|====|======|================|================|======================|===================|===================|==========|===========|========|============|";
    int choice;
    std::string vin;
    std::cout << "1. Search by VIN" << std::endl;
    std::cout << "2. Search by plate" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
        case 1:
            std::cout << "Introduceti VIN-ul: ";
            std::cin >> vin;
            for (int i = 0; i < n; i++)
            {
                if (vehicles[i].getVIN() == vin)
                {
                    std::cout << "Autoturismul gasit: " << std::endl << spacer << std::endl << header << std::endl << spacer << std::endl 
                                                        <<"| " << std::setw(2) << i+1 << " | " << vehicles[i] << std::endl << spacer << std::endl;
                    break;
                }
            }
            break;
        case 2:
            std::cout << "Introduceti placa: ";
            std::cin >> vin;
            for (int i = 0; i < n; i++)
            {
                if (vehicles[i].getPlate() == vin)
                {
                    std::cout << "Autoturismul gasit: " << std::endl << spacer << std::endl << header << std::endl << spacer << std::endl 
                                                        <<"| " << std::setw(2) << i+1 << " | " << vehicles[i] << std::endl << spacer << std::endl;
                    break;
                }
            }
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}   