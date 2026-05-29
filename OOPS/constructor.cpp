#include<iostream>
#include<string>
using namespace std;

class car {
    string name;
    string colour;

public:

    car() {
        cout << "constructor without parameters\n";
    }

    car(string name, string colour) {
        cout << "constructor is called. object being created\n";
        this->name = name;
        this->colour = colour;
    }

    void start() {
        cout << "your car has started\n";
    }

    void stop() {
        cout << "your car has stopped\n";
    }

    // getter
    string getname() {
        return name;
    }

    string getcolour() {
        return colour;
    }
};

int main() {
    car c0; // non-parameterized
    car c1("car", "orange"); // parameterized

    cout << "car name is : " << c1.getname() << endl;
    cout << "car colour is : " << c1.getcolour() << endl;

    return 0;
}
