#include <iostream>

class Car {

protected:
    std::string name, model;
    int year, price;

public:

    Car() {
        std::cout << "Using Car default constructor" << std::endl;
        Car::name = "N/a";
        Car::model = "N/a";
        Car::year = 0;
        Car::price = 0;
    }

    Car(std::string name, std::string model, int year, int price) {
        std::cout << "Using Car constructor" << std::endl;
        Car::name = name;
        Car::model = model;
        Car::year = year;
        Car::price = price;
    }

    Car(Car &car) {
        std::cout << "Using Car copy constructor" << std::endl;
        Car::name = car.name;
        Car::model = car.model;
        Car::year = car.year;
        Car::price = car.price;
    }

    void Show() {
        std::cout << "Car(name: " << Car::name << ", model: " << Car::model;
        std::cout << ", year: " << Car::year << ", price: " << Car::price << ")" << std::endl;
    }

    Car& operator =(Car &car) {
        Car::name = car.name;
        Car::model = car.model;
        Car::year = car.year;
        Car::price = car.price;
        return *this;
    }

    bool operator >(const Car &car) {
        return price > car.price;
    }

    bool operator <(const Car &car) {
        return price < car.price;
    }

    friend std::ostream& operator <<(std::ostream&, const Car&);
    friend std::istream& operator >>(std::istream&, Car&);

};

template<class T> class Truck : protected Car {

private:
    T lifting;

public:

    Truck() : Car() {
        std::cout << "Using default Truck constructor" << std::endl;
        lifting = 0;
    }

    Truck(std::string name, std::string model, int year, int price, T lifting) : Car(name, model, year, price) {
        std::cout << "Using Truck constructor" << std::endl;
        Truck::lifting = lifting;
    }

    Truck(Truck<T> &truck) : Car(truck) {
        std::cout << "Using copy Truck constructor" << std::endl;
        lifting = truck.lifting;
    }

    T GetLifting() {
        return lifting;
    }

    void SetLifting(T lifting) {
        Truck::lifting = lifting;
    }

    void Show() {
        std::cout << "Truck(name: " << name << ", model: " << model << ", year: ";
        std::cout << year << ", price: " << price << ", lifting: " << lifting << ")" << std::endl;
    }

    bool operator >(const Truck<T> &truck) {
        return truck.lifting < lifting;
    }

    bool operator <(const Truck<T> &truck) {
        return truck.lifting > lifting;
    }

    friend std::ostream& operator <<(std::ostream& out, const Truck& truck) {
        out << "Truck(name: " << truck.name << ", model: " << truck.model << ", year: ";
        out << truck.year << ", price: " << truck.price << ", lifting: " << truck.lifting << ")";
        return out;
    }

    friend std::istream& operator >>(std::istream& in, Truck& truck) {
        std::cout << "Name: ";
        in >> truck.name;
        std::cout << "Model: ";
        in >> truck.model;
        std::cout << "Year: ";
        in >> truck.year;
        std::cout << "Price: ";
        in >> truck.price;
        std::cout << "Lifting: ";
        in >> truck.lifting;
        return in;
    }

};

std::ostream &operator <<(std::ostream &out, const Car &car) {
    out << "Car(name: " << car.name << ", model: " << car.model;
    out << ", year: " << car.year << ", price: " << car.price << ")";
    return out;
}

std::istream &operator >>(std::istream &in, Car &car) {
    std::cout << "Name: ";
    in >> car.name;
    std::cout << "Model: ";
    in >> car.model;
    std::cout << "Year: ";
    in >> car.year;
    std::cout << "Price: ";
    in >> car.price;
    return in;
}

int main() {
    Truck<double> first("Volvo", "AAA", 2015, 5000000, 5250.5);
    Truck<int> second("KAMAZ", "A1", 2010, 3000000, 7000);
    Truck<int> third("MAN", "B2", 2020, 6000000, 6000);
    std::cout << "Тип грузоподъемности с плавающей точкой: " << first << std::endl;
    std::cout << "Целочисленный тип грузоподъемности: " << second << std::endl;
    std::cout << "Сравнение целочисленных грузоподъемностей (second > third): " << (second > third) << std::endl;
    return 0;
}
