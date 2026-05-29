#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//this is used to find the min of coins to make change for a value of v

int getminimumchange(vector<int>coins,int v){
    int ans=0;
    int n=coins.size();

    for(int i=n-1;i>=0 && v>0;i--){
        if(v>=coins[i]){
            int count=v/coins[i];
            ans+=count;
            cout<<coins[i]<<"x"<<count<<endl;
            v=v%coins[i];
        }
    }

    cout<<"min coins for change = "<<ans<<endl;
    return ans;
}


int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int v=1099;

    getminimumchange(coins,v);
    return 0;
}