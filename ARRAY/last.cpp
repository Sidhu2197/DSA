// code to check Last occurence
#include<iostream>
#include<vector>
using namespace std;

int LastOccurence(vector<int>arr,int i,int target){
    if(i == arr.size()){
        return -1;
    }

    int idxfound=LastOccurence(arr,i+1,target);
    if(idxfound == -1 && arr[i] == target){
        return i;
    }
    return idxfound;
}

int main(){
    vector<int>arr={1,3,2,3,4,5,3,9,1};
    cout<<"Last occurence is : "<<LastOccurence(arr,0,3);
    return 0;
}