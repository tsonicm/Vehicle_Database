#include "Vehicle.cpp"

int main()
{
    int n = 0;
    Vehicle vehicles[256];
    std::ifstream fIn;
    fIn.open("Database.txt");
    fIn >> n;
    for (int i = 0; i < n; i++)
    {
        fIn >> vehicles[i];
    }
    fIn.close();
    int choice;
    do
    {
        CLEAR();
        std::cout << "1. Add a new vehicle" << std::endl;
        std::cout << "2. Modify an existing vehicle" << std::endl;
        std::cout << "3. Delete an existing vehicle" << std::endl;
        std::cout << "4. Search for a vehicle" << std::endl;
        std::cout << "5. Print all vehicles" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                Add(vehicles, n);
                std::cout << "Press" << "\033[1;32m" << " 'Enter' " << "\033[0m" << "to continue...";
                fflush(stdin);
                getchar();
                break;
            case 2:
                Modify(vehicles, n);
                std::cout << "Press" << "\033[1;32m" << " 'Enter' " << "\033[0m" << "to continue...";
                fflush(stdin);
                getchar();
                break;
            case 3:
                Delete(vehicles, n);
                std::cout << "Press" << "\033[1;32m" << " 'Enter' " << "\033[0m" << "to continue...";
                fflush(stdin);
                getchar();
                break;
            case 4:
                Search(vehicles, n);
                std::cout << "Press" << "\033[1;32m" << " 'Enter' " << "\033[0m" << "to continue...";
                fflush(stdin);
                getchar();
                break;
            case 5:
                Print(vehicles, n);
                std::cout << "Press" << "\033[1;32m" << " 'Enter' " << "\033[0m" << "to continue...";
                fflush(stdin);
                getchar();
                break;
            case 6:
                break;
            default:
                std::cout << "\033[1;31m" << "Invalid choice!" << "\033[0m" << std::endl;
                fflush(stdin);
                getchar();
                break;
        }
    } while (choice != 6);
    std::ofstream fOut;
    fOut.open("Database.txt");
    fOut << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        fOut << vehicles[i].getYear() << " " << vehicles[i].getManufacturer() << " " << vehicles[i].getModel() << " " << vehicles[i].getColor() << " " << vehicles[i].getVIN() << " " << vehicles[i].getPlate() << " " << vehicles[i].getWeight() << " " << vehicles[i].getEngine() << " " << vehicles[i].getPower() << " " << vehicles[i].getSeats() << std::endl;
    }
    fOut.close();
    return 0;
}
