#include<iostream>
#include<string>  // Added missing string header
using namespace std;

class Animal {
public:
    string colour;

    void eat() {
        cout << "eats\n";
    }

    void breath() {
        cout << "breathes\n";
    }
};

class fish : public Animal {
public:
    int fins;

    void swim() {
        eat();
        cout << "swims\n";
    }
};

class bird : public Animal {
public:
    int wings;  // Changed from 'fly' to 'wings' - better variable name

    void fly() {  // Fixed: method name conflicted with variable name
        cout << "bird is flying\n";
    }
};

class mammal : public Animal {
public:
    int legs;  // Changed from 'ani' to 'legs' - more meaningful name
    
    void walk() {
        cout << "our mammal can walk\n";
    }
};

int main() {
    fish f1;
    f1.fins = 3;
    cout << f1.fins << endl;
    f1.swim();
    f1.eat();
    f1.breath();
    
    bird b1;
    b1.fly();
    
    // f1.walk();  // REMOVED - fish doesn't have walk() method
    // If you want to demonstrate mammal, create mammal object:
    mammal m1;
    m1.walk();
    
    return 0;
}