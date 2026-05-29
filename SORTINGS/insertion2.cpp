#include <iostream>
using namespace std;


void print(char arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortchar(char arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
    }
}

int main() {
    char ch[6]={'f','b','a','e','c','d'};
    sortchar(ch,6);
    
    return 0;
}