#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class CAR {
public:
    int idx;
    int distsq;

    CAR(int idx, int distsq) {
        this->idx = idx;
        this->distsq = distsq;
    }

    bool operator<(const CAR &obj) const {
        return this->distsq > obj.distsq; // Min-heap behavior
    }
};

void nearbycars(vector<pair<int, int>> pos, int k) {
    priority_queue<CAR> pq;

    for (int i = 0; i < pos.size(); i++) {
        int distsq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        pq.push(CAR(i, distsq));
    }

    for (int i=0;i<k;i++) {
        cout << "car " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;
    pos.push_back({3, 3});
    pos.push_back({5, -1});
    pos.push_back({-2, 4});

    int k = 2;
    nearbycars(pos, k);
    return 0;
}
