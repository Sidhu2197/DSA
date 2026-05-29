#include<iostream>
#include<string>
using namespace std;

class car {
    string name;
    string colour;
    int *mileage;

public:
    // Default constructor
    car() {
        cout << "constructor without parameters\n";
        name = "";
        colour = "";
        mileage = new int(0);  // Initialize with default value
    }

    // Parameterized constructor
    car(string name, string colour) {
        cout << "constructor is called. object being created\n";
        this->name = name;
        this->colour = colour;
        mileage = new int(12);  // Direct initialization
    }

    // Deep copy constructor
    car(car &original) {
        cout << "copying original to new .. \n";
        name = original.name;
        colour = original.colour;
        mileage = new int(*original.mileage);  // Deep copy - allocate new memory and copy value
    }

    // Destructor to prevent memory leak
    ~car() {
        delete mileage;
        cout << "destructor called for " << name << "\n";
    }

    void start() {
        cout << "your car has started\n";
    }

    void stop() {
        cout << "your car has stopped\n";
    }

    // Getters
    string getname() {
        return name;
    }

    string getcolour() {
        return colour;
    }

    int getmileage() {
        return *mileage;
    }

    // Setter for mileage (optional)
    void setmileage(int miles) {
        *mileage = miles;
    }
};

int main() {

    car c1("car", "orange"); // parameterized

    car c2(c1);  // copy constructor called
    
    // Access private members through getters
    cout << "c2 name: " << c2.getname() << endl;
    cout << "c2 colour: " << c2.getcolour() << endl;
    cout << "c2 mileage: " << c2.getmileage() << endl;

    // Demonstrate that it's a deep copy
    cout << "\nBefore modifying c1 mileage:\n";
    cout << "c1 mileage: " << c1.getmileage() << endl;
    cout << "c2 mileage: " << c2.getmileage() << endl;
    
    c1.setmileage(25);
    
    cout << "\nAfter modifying c1 mileage to 25:\n";
    cout << "c1 mileage: " << c1.getmileage() << endl;
    cout << "c2 mileage: " << c2.getmileage() << endl;

    return 0;
}