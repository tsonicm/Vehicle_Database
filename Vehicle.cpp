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
    os << "\033[1;34m" << std::setw(19) << v.getColor() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(16) << v.getVIN() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(17) << v.getPlate() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(8) << v.getWeight() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(8) << v.getEngine() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(7) << v.getPower() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
    os << "\033[1;34m" << std::setw(9) << v.getSeats() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
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
    std::cout << "Write data for the new vehicle: \n";
    std::cout << "Year: "; std::cin >> year;
    std::cout << "Manufacturer: "; std::cin >> manufacturer;
    std::cout << "Model: "; std::cin >> model;
    std::cout << "Color: "; std::cin >> color;
    std::cout << "VIN: "; std::cin >> vin;
    std::cout << "Plate: "; std::cin >> plate;
    std::cout << "Weight: "; std::cin >> weight;
    std::cout << "Engine: "; std::cin >> engine;
    std::cout << "Power: "; std::cin >> power;
    std::cout << "Seats: "; std::cin >> seats;
    vehicles[n] = Vehicle(year, manufacturer, model, color, vin, plate, weight, engine, power, seats);
    n++;
}

void ModifyYear(Vehicle vehicles[], int n) //Modify year function
{
    int choice, year;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new year: ";
        std::cin >> year;
        vehicles[choice - 1].setYear(year);
    }
}

void ModifyManufacturer(Vehicle vehicles[], int n) //Modify manufacturer function
{
    int choice;
    std::string manufacturer;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new manufacturer: ";
        std::cin >> manufacturer;
        vehicles[choice - 1].setManufacturer(manufacturer);
    }
}

void ModifyModel(Vehicle vehicles[], int n) //Modify model function
{
    int choice;
    std::string model;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new model: ";
        std::cin >> model;
        vehicles[choice - 1].setModel(model);
    }
}

void ModifyColor(Vehicle vehicles[], int n) //Modify color function
{
    int choice;
    std::string color;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new color: ";
        std::cin >> color;
        vehicles[choice - 1].setColor(color);
    }
}

void ModifyVIN(Vehicle vehicles[], int n) //Modify VIN function
{
    int choice;
    std::string vin;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new VIN: ";
        std::cin >> vin;
        vehicles[choice - 1].setVIN(vin);
    }
}

void ModifyPlate(Vehicle vehicles[], int n) //Modify plate function
{
    int choice;
    std::string plate;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new plate: ";
        std::cin >> plate;
        vehicles[choice - 1].setPlate(plate);
    }
}

void ModifyWeight(Vehicle vehicles[], int n) //Modify weight function
{
    int choice;
    int weight;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new weight: ";
        std::cin >> weight;
        vehicles[choice - 1].setWeight(weight);
    }
}

void ModifyEngine(Vehicle vehicles[], int n) //Modify engine function
{
    int choice;
    int engine;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new engine: ";
        std::cin >> engine;
        vehicles[choice - 1].setEngine(engine);
    }
}

void ModifyPower(Vehicle vehicles[], int n) //Modify power function
{
    int choice;
    int power;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new power: ";
        std::cin >> power;
        vehicles[choice - 1].setPower(power);
    }
}

void ModifySeats(Vehicle vehicles[], int n) //Modify seats function
{
    int choice;
    int seats;
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice < 1 || choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "Write the new number of seats: ";
        std::cin >> seats;
        vehicles[choice - 1].setSeats(seats);
    }
}

void Print(Vehicle vehicles[], int n) //Print function
{
    char header[155] = "| ID | Year |  Manufacturer  |      Model     |        Color        |        VIN        |       Plate       |  Weight  |  Engine  |  Power  |   Seats   |";
    char spacer[155] = "|====|======|================|================|=====================|===================|===================|==========|==========|=========|===========|";
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
            std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }
}

void Delete(Vehicle vehicles[], int &n) //Delete function
{
    int choice;
    Print(vehicles, n);
    std::cout << "Write the index of the vehicle from the table above: ";
    std::cin >> choice;
    if (choice > n)
    {
        std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
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
    char header[155] = "| ID | Year |  Manufacturer  |      Model     |        Color        |        VIN        |       Plate       |  Weight  |  Engine  |  Power  |   Seats   |";
    char spacer[155] = "|====|======|================|================|=====================|===================|===================|==========|==========|=========|===========|";
    int choice;
    std::string alegere;
    /// criterii
    std::string c_manufact = "-", c_model = "-", c_color = "-", c_vin = "-", c_plate = "-";
    int c_year = -1, c_weight = -1, c_engine = -1, c_seats = -1, c_power = -1;
    bool c_all = false;

    do{
    CLEAR();
    std::cout << "1. Search by year" << std::endl;
    std::cout << "2. Search by manufacturer" << std::endl;
    std::cout << "3. Search by model" << std::endl;
    std::cout << "4. Search by color" << std::endl;
    std::cout << "5. Search by VIN" << std::endl;
    std::cout << "6. Search by plate" << std::endl;
    std::cout << "7. Search by weight" << std::endl;
    std::cout << "8. Search by engine" << std::endl;
    std::cout << "9. Search by power" << std::endl;
    std::cout << "10. Search by seats" << std::endl;
    if(c_all == false)
        std::cout << "11. Show entire list" << std::endl;
    else std::cout << "11. Don't show entire list" << std::endl;

    /// verificare + afisare criterii
    int c_active = 0;
    if(c_manufact != "-") c_active++;
    if(c_model != "-") c_active++;
    if(c_color != "-") c_active++;
    if(c_vin != "-") c_active++;
    if(c_plate != "-") c_active++;
    if(c_year != -1) c_active++;
    if(c_weight != -1) c_active++;
    if(c_engine != -1) c_active++;
    if(c_power != -1) c_active++;
    if(c_seats != -1) c_active++;
    if(c_all != false) c_active++;

    if(c_active > 1)
        std::cout << std::endl << "There are " << c_active << " active criteria right now:" << std::endl;
    else if (c_active == 1)
        std::cout << std::endl << "There is " << c_active << " active criteria right now:" << std::endl;
    else
        std::cout << std::endl << "There are no active criteria right now." << std::endl;

    if(c_year != -1) std::cout << "Year: " << c_year << std::endl;
    if(c_manufact != "-") std::cout << "Manufacturer: " << c_manufact << std::endl;
    if(c_model != "-") std::cout << "Model: " << c_model << std::endl;
    if(c_color != "-") std::cout << "Color: " << c_color << std::endl;
    if(c_vin != "-") std::cout << "VIN: " << c_vin << std::endl;
    if(c_plate != "-") std::cout << "Plate: " << c_plate << std::endl;
    if(c_weight != -1) std::cout << "Weight: " << c_weight << std::endl;
    if(c_engine != -1) std::cout << "Engine: " << c_engine << std::endl;
    if(c_power != -1) std::cout << "Power: " << c_power << std::endl;
    if(c_seats != -1) std::cout << "Seats: " << c_seats << std::endl;
    if(c_all != false) std::cout << "Showing the entire list!" << std::endl;

    std::cout << std::endl << "Enter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
        case 1:
            std::cout << "Input year (input " << "\033[1;31m" << "-1" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_year;
            break;
        case 2:
            std::cout << "Input manufacturer (input " << "\033[1;31m" << "-" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_manufact;
            break;
        case 3:
            std::cout << "Input model (input " << "\033[1;31m" << "-" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_model;
            break;
        case 4:
            std::cout << "Input color (input " << "\033[1;31m" << "-" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_color;
            break;
        case 5:
            std::cout << "Input VIN (input " << "\033[1;31m" << "-" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_vin;
            break;
        case 6:
            std::cout << "Input plate (input " << "\033[1;31m" << "-" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_plate;
            break;
        case 7:
            std::cout << "Input weight (input " << "\033[1;31m" << "-1" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_weight;
            break;
        case 8:
            std::cout << "Input engine (input " << "\033[1;31m" << "-1" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_engine;
            break;
        case 9:
            std::cout << "Input power (input " << "\033[1;31m" << "-1" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_power;
            break;
        case 10:
            std::cout << "Input seats (input " << "\033[1;31m" << "-1" << "\033[0m" << " to disable this criteria): ";
            std::cin >> c_seats;
            break;
        case 11:
            if(c_all)
                std::cout << "\033[1;31m" << "No longer showing the entire list." << "\033[0m" << std::endl;
            else
                std::cout << "\033[1;32m" << "Now showing the entire list." << "\033[0m" << std::endl;

            c_all = !c_all;
            break;
        default:
            std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
    }

    bool exists = false;
    if (c_active == 0 || c_all) exists = true; /// daca nu exista conditii SAU afisam toata lista, atunci exists = true
    /// verificare cate masini indeplinesc conditia
    for(int i = 0; i < n && exists == false; i++)
    {
        bool ok = true;
        /// daca conditia e activa, verificare parametru in raport cu conditia
        if(c_year != -1) if(c_year != vehicles[i].getYear()) ok = false;
        if(c_manufact != "-") if(vehicles[i].getManufacturer().find(c_manufact) == std::string::npos) ok = false;
        if(c_model != "-") if(vehicles[i].getModel().find(c_model) == std::string::npos) ok = false;
        if(c_color != "-") if(vehicles[i].getColor().find(c_color) == std::string::npos) ok = false;
        if(c_vin != "-") if(vehicles[i].getVIN().find(c_vin) == std::string::npos) ok = false;
        if(c_plate != "-") if(vehicles[i].getPlate().find(c_plate) == std::string::npos) ok = false;
        if(c_weight != -1) if(c_weight != vehicles[i].getWeight()) ok = false;
        if(c_engine != -1) if(c_engine != vehicles[i].getEngine()) ok = false;
        if(c_power != -1) if(c_power != vehicles[i].getPower()) ok = false;
        if(c_seats != -1) if(c_seats != vehicles[i].getSeats()) ok = false;

        /// daca toate conditiile sunt adevarate, inseamna ca exista cel putin un vehicul de afisat
        if(ok) exists = true;
    }

    /// daca exists = true, afisare header, spacer si restul
    if(exists)
    {
        std::cout << "\033[1;35m" << spacer << std::endl << header << std::endl << spacer << std::endl << "\033[0m";
        for (int i = 0; i < n; i++)
        {
            if(c_all) /// afisare cu toata lista
            {
                std::string rosu_verde;
                std::cout << "\033[1;35m" << "| " << "\033[0m" << "\033[1;34m" << std::setw(2) << i+1 << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_year != -1) if(c_year != vehicles[i].getYear()) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(4) << vehicles[i].getYear() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_manufact != "-") if(vehicles[i].getManufacturer().find(c_manufact) == std::string::npos) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(14) << vehicles[i].getManufacturer() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_model != "-") if(vehicles[i].getModel().find(c_model) == std::string::npos) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(14) << vehicles[i].getModel() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_color != "-") if(vehicles[i].getColor().find(c_color) == std::string::npos) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(19) << vehicles[i].getColor() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_vin != "-") if(vehicles[i].getVIN().find(c_vin) == std::string::npos) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(16) << vehicles[i].getVIN() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_plate != "-") if(vehicles[i].getPlate().find(c_plate) == std::string::npos) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(17) << vehicles[i].getPlate() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_weight != -1) if(c_weight != vehicles[i].getWeight()) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(8) << vehicles[i].getWeight() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_engine != -1) if(c_engine != vehicles[i].getEngine()) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(8) << vehicles[i].getEngine() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_power != -1) if(c_power != vehicles[i].getPower()) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(7) << vehicles[i].getPower() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                rosu_verde = "\033[1;34m";
                if(c_seats != -1) if(c_seats != vehicles[i].getSeats()) rosu_verde = "\033[1;31m"; else rosu_verde = "\033[1;32m";
                std::cout << rosu_verde << std::setw(9) << vehicles[i].getSeats() << std::setw(0) << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";

                std::cout << std::endl << "\033[1;35m" << spacer << "\033[0m" << std::endl;
            }

            else /// afisare doar vehiculele care indeplinesc criteriile
            {
                bool ok = true;
                /// daca conditia e activa, verificare parametru in raport cu conditia
                if(c_year != -1) if(c_year != vehicles[i].getYear()) ok = false;
                if(c_manufact != "-") if(vehicles[i].getManufacturer().find(c_manufact) == std::string::npos) ok = false;
                if(c_model != "-") if(vehicles[i].getModel().find(c_model) == std::string::npos) ok = false;
                if(c_color != "-") if(vehicles[i].getColor().find(c_color) == std::string::npos) ok = false;
                if(c_vin != "-") if(vehicles[i].getVIN().find(c_vin) == std::string::npos) ok = false;
                if(c_plate != "-") if(vehicles[i].getPlate().find(c_plate) == std::string::npos) ok = false;
                if(c_weight != -1) if(c_weight != vehicles[i].getWeight()) ok = false;
                if(c_engine != -1) if(c_engine != vehicles[i].getEngine()) ok = false;
                if(c_power != -1) if(c_power != vehicles[i].getPower()) ok = false;
                if(c_seats != -1) if(c_seats != vehicles[i].getSeats()) ok = false;

                /// daca toate conditiile sunt adevarate, inseamna ca acest vehicul poate fi afisat
                if(ok)
                {
                    std::cout << "\033[1;35m" << "| " << "\033[0m" << "\033[1;34m" << std::setw(2) << i+1 << "\033[0m" << "\033[1;35m" << " | " << "\033[0m";
                    std::cout << vehicles[i] << '\n';
                    std::cout << "\033[1;35m" << spacer << "\033[0m" << std::endl;
                }
            }
        }
    }
    /// altfel, afisare "No entry found based on active criteria."
    else
        std::cout << std::endl << "\033[1;31m" << "No entry found based on active criteria." << "\033[0m" << std::endl;

    std::cout << std::endl << std::endl << "Do you wish to add/modify criteria? (" << "\033[1;32m" << "Y" << "\033[0m" << "/" << "\033[1;31m" << "N" << "\033[0m" << "): ";
    std::cin >> alegere;
    }while(alegere == "Y");
}

// Todokete setsuna sa ni wa
// Namae wo tsukeyou ka "Snow halation"
// sussy commentary
// baraka obamitai
// if cute and funny is cunny
// then funny and cute is fute
// cnv sa stearga aceste comentarii cand are timp
