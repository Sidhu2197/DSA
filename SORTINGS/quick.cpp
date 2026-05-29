#include <iostream>
#include <vector>
using namespace std;


void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int  partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[ei]);
    return i+1;
}


void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int pivoti=partition(arr,si,ei);

    quicksort(arr,si,pivoti-1);//left half
    quicksort(arr,pivoti+1,ei);//roght half
}
int main() {
    int arr[6]={6,3,7,5,2,4};
    int n=6;

    quicksort(arr,0,n-1);
    printArr(arr,6);
    return 0;
}