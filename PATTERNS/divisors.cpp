#include <iostream>
using namespace std;

void divisor(int n){
    int prod=1;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            prod=prod*i;
        }
    }
    cout<<"product is "<<prod;
}

int main() {
    int n;
    cin>>n;
    divisor(n);
    return 0;
}