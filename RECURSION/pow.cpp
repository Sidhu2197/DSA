#include<iostream>
using namespace std;

int pow(int x,int n){
    if(n==0){
        return 1;
    }

    int halfpower=pow(x,n/2);
    int halfpowersquare=halfpower*halfpower;

    if(n%2!=0){
        return x*halfpowersquare;
    }
    return halfpowersquare;
}

int main(){

    cout<<pow(2,6);
    return 0;
    
}