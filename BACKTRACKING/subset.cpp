#include<iostream>
#include<vector>
#include<string>
using namespace std;


void printsubsets(string str,string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }

char ch=str[0];

//yes kosam
printsubsets(str.substr(1,str.size()-1),subset+ch);
//no kosam
printsubsets(str.substr(1,str.size()-1),subset);

}

int main(){
    string str="abc";
    string subset="";
    printsubsets(str,subset);
    return 0;
}