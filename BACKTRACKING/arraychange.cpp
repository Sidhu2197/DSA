#include<iostream>
#include<vector>
#include<string>
using namespace std;


//function array nin print cheyadam kosam
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}


//array declaration

void changearr(int arr[],int n,int i){
    if(i==n){
        printarr(arr,n);
        return;
    }
    arr[i]=i+1;
    changearr(arr,n,i+1);
    arr[i]=arr[i]-2;
}
int main(){
    int arr[5]={0};
    int n=5;
    changearr(arr,n,0);
    printarr(arr,n);
    return 0;
}