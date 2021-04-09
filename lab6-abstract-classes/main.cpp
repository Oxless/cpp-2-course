#include <iostream>

class Car {

protected:

    std::string name, model;
    int year, price;

    Car() {
        std::cout << "Using default constructor of abstract class" << std::endl;
        name = "N/a";
        model = "N/a";
        year = 0;
        price = 0;
    }

    Car(std::string name, std::string model, int year, int price) {
        std::cout << "Using constructor of abstract class" << std::endl;
        Car::name = name;
        Car::model = model;
        Car::year = year;
        Car::price = price;
    }

public:
    virtual void Show() = 0;

};

class Truck : protected Car {

private:
    int lifting;

public:

    Truck() : Car() {
        std::cout << "Using default constructor of Truck" << std::endl;
        lifting = 0;
    }

    Truck(std::string name, std::string model, int year, int price, int lifting) : Car(name, model, year, price) {
        std::cout << "Using constructor of Truck" << std::endl;
        Truck::lifting = lifting;
    }

    void Show() override {
        std::cout << "Truck(name: " << name << ", model: " << model << ", year: " << year;
        std::cout << ", price: " << price << ", lifting: " << lifting << ")" << std::endl;
    }

};

class Bus : protected Car {

private:
    int roominess;



public:

    Bus() : Car() {
        std::cout << "Using default constructor of Bus" << std::endl;
        roominess = 0;
    }

    Bus(std::string name, std::string model, int year, int price, int roominess) : Car(name, model, year, price) {
        std::cout << "Using constructor of Bus" << std::endl;
        Bus::roominess = roominess;
    }

    void Show() override {
        std::cout << "Bus(name: " << name << ", model: " << model << ", year: " << year;
        std::cout << ", price: " << price << ", roominess: " << roominess << ")" << std::endl;
    }

};

int main() {
    //Появилось поле "грузоподъемность"
    Truck truck("Volvo", "1234", 2020, 5000000, 4000);
    truck.Show();
    //Появилось поле "вместительность"
    Bus bus("Mercedes", "Bus", 2015, 4000000, 50);
    bus.Show();
    return 0;
}
