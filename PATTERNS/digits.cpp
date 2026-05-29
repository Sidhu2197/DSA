#include <iostream>
using namespace std;

void print_digits(int n){
    int dig;
    if (n<0){
    n=n*-1;
    }
    while(n>0){
        dig=n%10;
        n=n/10;
        cout<<dig<<" ";
    }
}



int main() {
    int n;
    cin>>n;
    
    print_digits(n);
    return 0;
}