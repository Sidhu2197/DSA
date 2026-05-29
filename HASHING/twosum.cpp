#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[7]={1,2,7,11,15,5,9};
    int n=7;
    int target=9;
    unordered_map<int,int> m;//key = arr[i] and value will be index

    for(int i=0;i<n;i++){
        int meow = target - arr[i];
        if(m.count(meow)){
            cout<<"ans : "<<m[meow]<<","<<i<<endl;
            break;
        }
        m[arr[i]]=i;
    }
}