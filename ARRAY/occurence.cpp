// code to check first occurence
#include<iostream>
#include<vector>
using namespace std;

int FirstOcuur(vector<int>arr,int i,int target){
    if(i == arr.size()){
        return -1;
    }

    if(arr[i] == target){
        return i;
    }

    return FirstOcuur(arr,i+1,target);
}

int main(){
    vector<int>arr={1,3,2,3,4,5,3,9};
    cout<<"Index Number is : "<<FirstOcuur(arr,0,3);
    return 0;
}