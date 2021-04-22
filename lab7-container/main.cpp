#include <iostream>
#include <vector>

class Car {

public:
    std::string name, model;

    Car() {
        name = "N/a";
        model = "N/a";
    }

    Car(std::string name, std::string model) {
        Car::name = name;
        Car::model = model;
    }

};

class CarList {

    std::vector<Car> cars;

public:

    CarList() {}

    CarList(const Car& first) {
        cars.push_back(first);
    }

    void Add(const Car& car) {
        cars.push_back(car);
    }

    void Show() {
        std::cout << "CarList:" << std::endl;
        for(const Car& car : cars) {
            std::cout << "- Car(name: " << car.name << ", model: " << car.model << ")" << std::endl;
        }
    }

};

int main() {
    Car first("Lada", "Kalina");
    Car second("Mazda", "RX-8");
    Car third("Reno", "Logan");
    CarList carList(first);
    carList.Add(second);
    carList.Add(third);
    carList.Show();
}
