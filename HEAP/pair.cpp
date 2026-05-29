#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct comparepair {
    bool operator()(pair<string,int>& p1, pair<string,int>& p2) {
        return p1.second < p2.second; // max-heap by marks
    }
};

int main() {
    priority_queue<pair<string,int>, vector<pair<string,int>>, comparepair> pq;

    pq.push(make_pair("tony", 500));
    pq.push(make_pair("meow", 1000));
    pq.push(make_pair("optimus", 100));

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << " , " << pq.top().second << endl;
        pq.pop();
    }
    
    return 0;
}
