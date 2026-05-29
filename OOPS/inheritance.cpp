#include<iostream>
using namespace std;

class Animal{
    public:
    string colour;

    void eat(){
        cout<<"eats\n";
    }

    void breath(){
        cout<<"breathes\n";
    }
};

class fish : public Animal{
    public:
    int fins;

    void swim(){
        eat();
        cout<<"swims\n";
    }
};

int main(){
    fish f1;
    f1.fins =3;
    cout<<f1.fins<<endl;
    f1.swim();
    f1.eat();
    f1.breath();
    return 0;

}