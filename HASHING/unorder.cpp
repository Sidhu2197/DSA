#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int>m;

    m["china"]=150;
    m["india"]=150;
    m["us"]=50;
    m["nepal"]=10;

    // for(pair<string,int> country:m){
    //     cout<<country.first<<","<<country.second<<endl;
    // }

    m.erase("nepal");

    if(m.count("nepal")){
        cout<<"nepal exists\n";
    }
    else
    {
        cout<<"nepal does not exists";
    }
    return 0;
}