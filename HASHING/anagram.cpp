// anagram means same characters and same number of times
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

bool anagram(string s,string t){
    if(s.size()!=t.size()){
        return false;
    }
    //1st step-> s<char,freq>
    unordered_map<int,int>freq;
    for(int i=0;i<s.size();i++){
        if(freq.count(s[i])){
            freq[s[i]]++;
        else
        {
            freq[s[i]]=1;
        }
    }

    //2nd step->look for t's charcters in frequency

    for(int i=0;i<t.size();i++){
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]] == 0){
                freq.erase(t[i]);
            }
        }
        else
        {
            return false;
        }
    }
    return freq.size()==0;
}

int main(){
    string s="race";
    string t="care";
    cout<<anagram(s,t);
}