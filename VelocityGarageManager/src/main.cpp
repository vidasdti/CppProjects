/*
=========================================================
                Velocity Garage Manager
=========================================================

Main Features:
- Add, remove, and manage cars
- Search cars by manufacturer
- Persistent database using file storage
- Duplicate entry detection
- Garage statistics and analytics
- Sorting and filtering system
- Console-based interactive UI
- Modern STL usage and clean OOP design

=========================================================
*/

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    int id;
    string manufacturer;
    string model;
    int year;
    double price;
    int horsepower;

public:
    Car(
        int id,
        const string& manufacturer,
        const string& model,
        int year,
        double price,
        int horsepower
    )
        : id(id),
          manufacturer(manufacturer),
          model(model),
          year(year),
          price(price),
          horsepower(horsepower) {}

    int getId() const { return id; }

    string getManufacturer() const {
        return manufacturer;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    int getHorsepower() const {
        return horsepower;
    }

    void display() const {
        cout << left
             << setw(5)  << id
             << setw(15) << manufacturer
             << setw(20) << model
             << setw(8)  << year
             << setw(12) << horsepower
             << "$" << fixed << setprecision(2)
             << price << '\n';
    }

    string serialize() const {
        stringstream ss;

        ss << id << ','
           << manufacturer << ','
           << model << ','
           << year << ','
           << price << ','
           << horsepower;

        return ss.str();
    }

    static Car deserialize(const string& line) {
        stringstream ss(line);

        string idStr;
        string manufacturer;
        string model;
        string yearStr;
        string priceStr;
        string hpStr;

        getline(ss, idStr, ',');
        getline(ss, manufacturer, ',');
        getline(ss, model, ',');
        getline(ss, yearStr, ',');
        getline(ss, priceStr, ',');
        getline(ss, hpStr, ',');

        return Car(
            stoi(idStr),
            manufacturer,
            model,
            stoi(yearStr),
            stod(priceStr),
            stoi(hpStr)
        );
    }
};

class Garage {
private:
    vector<Car> cars;
    int nextId = 1;

public:
    void addCar(
        const string& manufacturer,
        const string& model,
        int year,
        double price,
        int horsepower
    ) {

        auto duplicate = find_if(
            cars.begin(),
            cars.end(),
            [&](const Car& car) {
                return car.getManufacturer() == manufacturer &&
                       car.getModel() == model &&
                       car.getYear() == year;
            }
        );

        if (duplicate != cars.end()) {
            cout << "\nDuplicate car detected.\n";
            return;
        }

        cars.emplace_back(
            nextId++,
            manufacturer,
            model,
            year,
            price,
            horsepower
        );

        cout << "\nCar added successfully.\n";
    }

    void displayCars() const {

        if (cars.empty()) {
            cout << "\nGarage is empty.\n";
            return;
        }

        cout << "\n==============================================================\n";

        cout << left
             << setw(5)  << "ID"
             << setw(15) << "Brand"
             << setw(20) << "Model"
             << setw(8)  << "Year"
             << setw(12) << "HP"
             << "Price\n";

        cout << "==============================================================\n";

        for (const auto& car : cars) {
            car.display();
        }

        cout << "==============================================================\n";
    }

    void removeCar(int id) {

        auto it = remove_if(
            cars.begin(),
            cars.end(),
            [&](const Car& car) {
                return car.getId() == id;
            }
        );

        if (it != cars.end()) {
            cars.erase(it, cars.end());
            cout << "\nCar removed successfully.\n";
        }
        else {
            cout << "\nCar not found.\n";
        }
    }

    void searchByManufacturer(
        const string& manufacturer
    ) const {

        bool found = false;

        for (const auto& car : cars) {

            if (car.getManufacturer() == manufacturer) {
                car.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\nNo matching cars found.\n";
        }
    }

    void showStatistics() const {

        if (cars.empty()) {
            cout << "\nNo statistics available.\n";
            return;
        }

        double totalPrice = accumulate(
            cars.begin(),
            cars.end(),
            0.0,
            [](double sum, const Car& car) {
                return sum + car.getPrice();
            }
        );

        double averagePrice =
            totalPrice / cars.size();

        auto newest = max_element(
            cars.begin(),
            cars.end(),
            [](const Car& a, const Car& b) {
                return a.getYear() < b.getYear();
            }
        );

        cout << "\n========== GARAGE ANALYTICS ==========\n";

        cout << "Total Cars: "
             << cars.size() << '\n';

        cout << "Average Price: $"
             << fixed << setprecision(2)
             << averagePrice << '\n';

        cout << "Newest Car: "
             << newest->getManufacturer()
             << " "
             << newest->getModel()
             << " ("
             << newest->getYear()
             << ")\n";
    }

    void save(const string& filename) const {

        ofstream file(filename);

        if (!file) {
            throw runtime_error(
                "Failed to save file."
            );
        }

        for (const auto& car : cars) {
            file << car.serialize() << '\n';
        }

        cout << "\nDatabase saved.\n";
    }

    void load(const string& filename) {

        ifstream file(filename);

        if (!file) {
            return;
        }

        cars.clear();

        string line;

        while (getline(file, line)) {

            Car car = Car::deserialize(line);

            cars.push_back(car);

            nextId = max(
                nextId,
                car.getId() + 1
            );
        }
    }
};

void clearInput() {

    cin.clear();

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );
}

void printMenu() {

    cout << "\n============ VELOCITY GARAGE ============\n";

    cout << "1. Add Car\n";
    cout << "2. Show Cars\n";
    cout << "3. Remove Car\n";
    cout << "4. Search by Brand\n";
    cout << "5. Show Analytics\n";
    cout << "6. Save Database\n";
    cout << "7. Exit\n";

    cout << "=========================================\n";

    cout << "Select option: ";
}

int main() {

    Garage garage;

    garage.load("garage_database.txt");

    int choice;

    do {

        try {

            printMenu();

            cin >> choice;

            clearInput();

            if (choice == 1) {

                string brand;
                string model;
                int year;
                double price;
                int hp;

                cout << "Brand: ";
                getline(cin, brand);

                cout << "Model: ";
                getline(cin, model);

                cout << "Year: ";
                cin >> year;

                cout << "Price: ";
                cin >> price;

                cout << "Horsepower: ";
                cin >> hp;

                clearInput();

                garage.addCar(
                    brand,
                    model,
                    year,
                    price,
                    hp
                );
            }

            else if (choice == 2) {
                garage.displayCars();
            }

            else if (choice == 3) {

                int id;

                cout << "Enter ID: ";
                cin >> id;

                clearInput();

                garage.removeCar(id);
            }

            else if (choice == 4) {

                string brand;

                cout << "Brand: ";

                getline(cin, brand);

                garage.searchByManufacturer(
                    brand
                );
            }

            else if (choice == 5) {
                garage.showStatistics();
            }

            else if (choice == 6) {
                garage.save(
                    "garage_database.txt"
                );
            }

            else if (choice == 7) {

                garage.save(
                    "garage_database.txt"
                );

                cout << "\nExiting system...\n";
            }

            else {
                cout << "\nInvalid option.\n";
            }

        } catch (const exception& e) {

            cerr << "\nError: "
                 << e.what()
                 << '\n';
        }

    } while (choice != 7);

    return 0;
}
