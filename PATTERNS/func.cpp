// pass by reference

void dosomething(int num){
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;

}

#include <iostream>
using namespace std;
int main() {
    int num=10;
    dosomething(num);
    cout<<num<<endl;
    
    return 0;
}