#include<iostream>
using namespace std;

int main(){
    int n,key,flag=0;
    cin>>n>>key;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];

        if(arr[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"the key element is present in the array"<<endl;
    }
    else{
        cout<<"the key element is not present in the array";
    }
    return 0;
}