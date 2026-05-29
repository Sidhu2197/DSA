#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//the term unbounded knapsack means we can pick
//thing multiple time for max profit

int unbounded(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){  // Fixed: changed 'i' to 'j' in condition
            int itemval = val[i-1];
            int itemwt = wt[i-1];

            if(itemwt <= j){
                // For unbounded knapsack, we use dp[i][j-itemwt] instead of dp[i-1][j-itemwt]
                // because we can reuse the same item multiple times
                dp[i][j] = max(itemval + dp[i][j-itemwt], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];  // Added missing return statement
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;
    cout << "Maximum value: " << unbounded(val, wt, w, n) << endl;
    return 0;
}