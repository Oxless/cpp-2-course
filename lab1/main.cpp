#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Car {
    string name, model, country;
    int year, mileage, price, amount;
    double engine;
    Car* next;
};

class CarList {

private:
    Car* firstElement;
    Car* lastElement;
    int size;

public:

    CarList() {
        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
    }

    CarList(string name, string model, string country, int year, int mileage, int price, int amount, double engine) {
        Car* start = new Car;
        start->name = name;
        start->model = model;
        start->country = country;
        start->year = year;
        start->mileage = mileage;
        start->price = price;
        start->amount = amount;
        start->engine = engine;
        start->next = nullptr;
        firstElement = start;
        lastElement = start;
        size = 1;
    }

    CarList(CarList &list) {
        firstElement = nullptr;
        lastElement = nullptr;
        size = list.size;
        Car* current = list.firstElement;
        while(current) {
            Car* temp = new Car;
            temp->name = current->name;
            temp->model = current->model;
            temp->country = current->country;
            temp->year = current->year;
            temp->mileage = current->mileage;
            temp->price = current->price;
            temp->amount = current->amount;
            temp->engine = current->engine;
            temp->next = current->next;
            if(!firstElement) {
                firstElement = temp;
                lastElement = temp;
            } else {
                lastElement->next = temp;
                lastElement = temp;
            }
            current = current->next;
        }
    }
    
    ~CarList() {
        while (firstElement){
            Car* next  = firstElement->next;
            delete firstElement;
            firstElement = next;
        }
        delete lastElement;
        size = 0;
    }

    void AddElement(string name, string model, string country, int year, int mileage, int price, int amount, double engine) {
        Car* temp = new Car;
        temp->name = name;
        temp->model = model;
        temp->country = country;
        temp->year = year;
        temp->mileage = mileage;
        temp->price = price;
        temp->amount = amount;
        temp->engine = engine;
        temp->next = nullptr;
        if(!firstElement) {
            firstElement = temp;
            lastElement = temp;
        } else {
            lastElement->next = temp;
            lastElement = temp;
        }
        size++;
    }

    void Show() {
        Car* first = firstElement;
        while(first) {
            cout << "Name: " << first->name << ", model: " << first->model << ", country: " << first->country;
            cout << ", year: " << first->year << ", mileage: " << first->mileage << ", price: " << first->price;
            cout << ", amount: " << first->amount << ", engine: " << first->engine << endl;
            first = first->next;
        }
    }

    int Size() {
        return size;
    }
    
    bool operator >(const CarList &list) {
        return size > list.size;
    }
    
    bool operator <(const CarList &list) {
        return size < list.size;
    }
    
    void operator =(const CarList &list) {
        firstElement = nullptr;
        lastElement = nullptr;
        size = list.size;
        Car* current = list.firstElement;
        while(current) {
            Car* temp = new Car;
            temp->name = current->name;
            temp->model = current->model;
            temp->country = current->country;
            temp->year = current->year;
            temp->mileage = current->mileage;
            temp->price = current->price;
            temp->amount = current->amount;
            temp->engine = current->engine;
            temp->next = current->next;
            if(!firstElement) {
                firstElement = temp;
                lastElement = temp;
            } else {
                lastElement->next = temp;
                lastElement = temp;
            }
            current = current->next;
        }
    }

    friend ostream& operator <<(ostream &, const CarList &);
    friend istream& operator >>(istream &, CarList &);

};

ostream& operator <<(ostream& out, const CarList &list) {
    Car* first = list.firstElement;
    while(first) {
        out << "Name: " << first->name << ", model: " << first->model << ", country: " << first->country;
        out << ", year: " << first->year << ", mileage: " << first->mileage << ", price: " << first->price;
        out << ", amount: " << first->amount << ", engine: " << first->engine << endl;
        first = first->next;
    }
    return out;
}

istream& operator >>(istream &in, CarList &list) {
    Car* car = new Car;
    cout << "Name: ";
    in >> car->name;
    cout << "Model: ";
    in >> car->model;
    cout << "Country: ";
    in >> car->country;
    cout << "Year: ";
    in >> car->year;
    cout << "Mileage: ";
    in >> car->mileage;
    cout << "Price: ";
    in >> car->price;
    cout << "Amount: ";
    in >> car->amount;
    cout << "Engine: ";
    in >> car->engine;
    list.firstElement = car;
    list.lastElement = car;
    return in;
}

int main() {
    CarList list;
    cin >> list;
    list.Show();
}
