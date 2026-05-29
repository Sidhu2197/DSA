#include<iostream>
#include<queue>
using namespace std;

// for first non repeating in a given string

void first(string str){
    queue<char> q;
    int freq[26]={0};

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        q.push(ch);
        freq[ch-'a']++;

        while(!q.empty() && freq[q.front()]>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1\n";
        }
        else
        {
            cout<<q.front()<<"\n";
        }
    }
}
int main(){
    string str="asbhdwb";
    first(str);
    return 0;
}