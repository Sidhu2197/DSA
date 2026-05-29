#include <iostream>
using namespace std;


void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=n+1;j<n;j++){
            if (arr[j]<arr[min]){
                min=j;
                swap(arr[i],arr[min]);
            }
        }
    }
}

int main() {
    int arr[5] = {5, 4, 1, 3, 2};
    print(arr,5);
    sort(arr, 5);
    return 0;
}
