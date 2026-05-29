#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={4,58,589,696,4,85,-1};

    int n=arr.size();

    int max=arr[0];
    int min=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }

        if(arr[i]<min){
            min=arr[i];
        }
    }

    cout<<"maximum number is :"<<max<<endl;
    cout<<"minimum number is :"<<min<<endl;


}