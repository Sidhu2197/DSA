// #include <iostream>
// using namespace std;
// int main() {
//     int num1,num2;
//     cin>>num1>>num2;
//     int minimum = max(num1,num2);
//     cout<<minimum;
//     return 0;
// }




#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    cout << "Minimum: " << minimum << endl;
    return 0;
}
