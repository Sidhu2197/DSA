#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int binomial(int n,int r){
    int val1=factorial(n);
    int val2=factorial(r);
    int val3=factorial(n-r);

    int result=val1/(val2*val3);
    cout<<result;
}

int main(){
    binomial(3,2);
    return 0;
    
}