#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>start={0,1,2};
    vector<int>end  ={9,2,4};
    
    vector<pair<int,int>>activities;
    
    for(int i = 0; i < start.size(); i++){
        activities.push_back({end[i], start[i]});
    }
    
    sort(activities.begin(), activities.end());
    
    int count = 1;
    int lastEnd = activities[0].first;
    
    for(int i = 1; i < activities.size(); i++){
        if(activities[i].second >= lastEnd){
            count++;
            lastEnd = activities[i].first;
        }
    }
    
    cout << count << endl;
    
    return 0;
}