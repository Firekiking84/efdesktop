#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructeur principal
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Constructeur principal appelé\n";
    }

    // Constructeur qui délègue au constructeur principal
    Person() : Person("Inconnu", 0) {
        std::cout << "Constructeur par défaut appelé\n";
    }

    // Un autre constructeur qui délègue au constructeur principal
    Person(const std::string& name) : Person(name, 0) {
        std::cout << "Constructeur avec nom appelé\n";
    }

    void display() const {
        std::cout << "Nom: " << name << ", Age: " << age << '\n';
    }
};

int main() {
    Person p1;                // Appel du constructeur par défaut
    Person p2("Alice");       // Appel du constructeur avec nom
    Person p3("Bob", 25);     // Appel du constructeur principal

    p1.display();
    p2.display();
    p3.display();

    return 0;
}
