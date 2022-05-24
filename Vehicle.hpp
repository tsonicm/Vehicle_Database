#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <vector>

class Vehicle
{
    private:
        int year;
        std::string manufacturer;
        std::string model;
        std::string color;
        std::string vin;
        std::string plate;
        int weight;
        int engine;
        int power;
        int seats;
    public:
        Vehicle();
        Vehicle(int year, std::string manufacturer, std::string model, std::string color, std::string vin, std::string plate, int weight, int engine, int power, int seats);
        ~Vehicle();
        int getYear();
        std::string getManufacturer();
        std::string getModel();
        std::string getColor();
        std::string getVIN();
        std::string getPlate();
        int getWeight();
        int getEngine();
        int getPower();
        int getSeats();
        void setYear(int year);
        void setManufacturer(std::string manufacturer);
        void setModel(std::string model);
        void setColor(std::string color);
        void setVIN(std::string vin);
        void setPlate(std::string plate);
        void setWeight(int weight);
        void setEngine(int engine);
        void setPower(int power);
        void setSeats(int seats);
        friend std::ostream& operator<< (std::ostream& os, const Vehicle& v);
        friend std::istream& operator>> (std::istream& is, Vehicle& v);
};