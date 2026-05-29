#include<iostream>
using namespace std;

void hello(){
    cout<<"hi meow :-)\n";
}

void meow(){
    hello();
    cout<<"did you eat?";
}

int main(){
    meow();
    return 0;

}