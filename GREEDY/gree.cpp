#include <bits/stdc++.h>
using namespace std;

// function to calculate the minimum cost

int cost(vector<int>& a)
{
    // Minimum cost is (size - 1) multiplied with minimum element.
    int n = a.size();
    return (n - 1) * (*min_element(a.begin(), a.end()));
}

int main()
{
    vector<int> a = {5, 4, 3, 2 };
    cout << cost(a) << endl;
    cout<<a.size();
    return 0;
}