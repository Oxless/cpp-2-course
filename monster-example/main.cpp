#include <iostream>

class Monster {

    int health, ammo;
    std::string name;

public:

    Monster(std::string name = "", int health = 100, int ammo = 10) {
        this->name = name;
        this->health = health;
        this->ammo = ammo;
    }

    Monster(Monster &monster) {
        this->name = monster.name;
        this->health = monster.health;
        this->ammo = monster.ammo;
        std::cout << "Used copy constructor" << std::endl;
    }

    std::string GetName() { return name; }
    int GetHealth() { return health; }
    int GetAmmo() { return ammo; }

    void SetName(std::string newName) { name = newName; }
    void SetHealth(int newHealth) { health = newHealth; }
    void SetAmmo(int newAmmo) { ammo = newAmmo; }
    void Show() {
        std::cout << "Monster(name: " << name << ", health: " << health << ", ammo: " << ammo << ")" << std::endl;
    }

    Monster & operator ++() {
        ++health;
        return *this;
    }

    Monster & operator --() {
        --health;
        return *this;
    }

    bool operator >(const Monster &monster) {
        return health > monster.health;
    }

    bool operator <(const Monster &monster) {
        return health < monster.health;
    }

    Monster& operator =(const Monster &monster) {
        if(&monster == this) return *this;
        name = monster.name;
        health = monster.health;
        ammo = monster.ammo;
        std::cout << "Monster copied" << std::endl;
        return *this;
    }

    friend std::ostream& operator <<(std::ostream &, const Monster &);
    friend std::istream& operator >>(std::istream &, Monster &);

};

std::ostream& operator <<(std::ostream &out, const Monster &monster) {
    out << "Monster(name: " << monster.name << ", health: " << monster.health << ", ammo: " << monster.ammo << ")";
    return out;
}

std::istream& operator >>(std::istream &in, Monster &monster) {
    std::cout << "Name: ";
    in >> monster.name;
    std::cout << "Health: ";
    in >> monster.health;
    std::cout << "Ammo: ";
    in >> monster.ammo;
    return in;
}

int main() {
    Monster goblin("Goblin", 50, 10);
    //Вывод монстра на экран
    goblin.Show();
    //Копирование объекта
    Monster goblinCopy(goblin);
    Monster ork;
    //Ввод объекта с клавиатуры
    std::cin >> ork;
    //Сравнение объектов
    std::cout << "Здоровье Goblin больше здоровья Ork: " << (goblinCopy > ork) << std::endl;
    //Присвоение объекта
    goblin = ork;
    //Вывод присвоенного объекта
    std::cout << goblin << std::endl;
    //Перегрузка унарных операций
    std::cout << "Здоровье Goblin: " << (++goblinCopy).GetHealth() << std::endl;
    return 0;
}
