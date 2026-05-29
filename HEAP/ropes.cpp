// Connect N Ropes - Minimum Cost Problem
// min heap
// Problem: Given N ropes with different lengths, connect them into one rope.
// Cost to connect 2 ropes = sum of their lengths
// Goal: Find minimum cost to connect all ropes

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connect_ropes(vector<int>ropes){
    priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());

    int cost=0;
    while(pq.size()>1)
    {
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();

        cost+=min1+min2;
        pq.push(min1+min2);
    }

    cout<<"min cost = "<<cost<<endl;
};


int main(){
    vector<int>ropes={4,3,2,6};
    connect_ropes(ropes);
    return 0;
}