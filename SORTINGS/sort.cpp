#include <iostream>
#include <algorithm>  // For sort()
using namespace std;

// Function to print the array
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[8] = {1, 4, 1, 4, 3, 2, 4, 7};

    // In-built sort for descending order
    sort(arr, arr + 8);
    print(arr, 8);  // Output the sorted array
    return 0;
}
