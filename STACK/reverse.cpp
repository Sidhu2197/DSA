#include<iostream>
#include<stack>
#include<string>
using namespace std;


string reverse(string str){ // TC:SC = 0(N):0(N)
    string ans;
    stack<char>s;

    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char top=s.top();
        ans+=top;
        s.pop();
    }
    return ans;

};

int main(){
    string str="abcd";
    // string str="123456";
    cout<<"reverse = "<<reverse(str)<<endl;
    return 0;
}