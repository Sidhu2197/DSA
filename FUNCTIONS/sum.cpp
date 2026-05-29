#include<iostream>
using namespace std;

int meow(int a,int b){
    int sum=a+b;
    return sum;
}

int dogesh(int a,int b){
    int diff=a-b;
    return diff;
}

int prod(int a,int b){
    int meow=a*b;
    return meow;
}

void check(int a){
    if(a%2==0){
        cout<<"given number is even number";
    }
    else
    {
        cout<<"given number is odd number";
    }
}

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return (n)*factorial(n-1);
}

int prime(int n){
    if(n<=1){
        return 0;
    }

    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cout<<prime(2);
    return 0;
}