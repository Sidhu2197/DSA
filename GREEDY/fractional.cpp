#include<iostream>
#include<vector>
#include<algorithm> // Needed for sort
using namespace std;

// Comparison function to sort by ratio in descending order
bool compare(pair<double,int> p1, pair<double,int> p2) {
    return p1.first > p2.first;
}

double fractional(vector<int> val, vector<int> wt, int w) {
    int n = val.size();
    vector<pair<double,int>> ratio(n); // pair(ratio, index)

    // Calculate value/weight ratio for each item
    for(int i = 0; i < n; i++) {
        double r = (double)val[i] / wt[i]; // ✅ fixed to use floating point division
        ratio[i] = make_pair(r, i);
    }

    // Sort items by ratio in descending order
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0;

    for(int i = 0; i < n; i++) {
        int idx = ratio[i].second;
        if(wt[idx] <= w) {
            ans += val[idx];
            w -= wt[idx];
        } else {
            ans += ratio[i].first * w;
            break; // Knapsack is full
        }
    }

    cout << "max value = " << ans << endl;
    return ans;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int w = 50;

    fractional(val, wt, w);

    return 0;
}
