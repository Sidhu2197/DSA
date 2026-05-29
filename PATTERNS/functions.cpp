//using function take two functions and print it's sum
int sum(int num1,int num2){
    int num3=num1+num2;//5+6=11
    return num3;
}

#include <iostream>
using namespace std;
int main() {
    int num1,num2;
    cin>>num1>>num2;
    int res = sum(num1,num2);
    cout<<res;
    return 0;
}

