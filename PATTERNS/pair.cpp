#include <iostream>
using namespace std;

void pairex(){
    // pair<int, int> p = {1,3};
    // cout<<p.first<<" "<<p.second;

    // pair<int,pair<int,int>> p = {1,{3,4}};
    // cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;

    pair<int,int>arr[]={{1,2},{2,5},{5,1}};
    cout<<arr[0].first<< " "<<arr[0].second<<" " <<arr[1].first<< " "<<arr[1].second<<" "<<arr[2].first<< " "<<arr[2].second;


}
int main() {
    pairex();
    return 0;
}