#include <iostream>
using namespace std;

// bubble sort is nothing sorting in ascending order or desending order by swapping
//(n-1)turns should be done


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);
}

int main() {
    int arr[5]={5,4,1,3,2};
    sort(arr,5);
    return 0;
}