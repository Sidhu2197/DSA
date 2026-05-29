#include <iostream>
using namespace std;
int main() {
    int day;
    cin>>day;

    switch(day){
        case 1:
        cout<<"MONDAY";
        break;
        case 2:
        cout<<"TUESDAY";
        break;
        case 3:
        cout<<"WEDNESDAY";
        break;
        case 4:
        cout<<"thursday";
        break;
        case 5:
        cout<<"friday";
        break;
        case 6:
        cout<<"saturday";
        break;
        case 7:
        cout<<"sunday";
        break;
        default:
        cout<<"invalid"<<endl;
    }
    cout<<"check inside switch";


    return 0;
}