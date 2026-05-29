#include<iostream>
#include <climits>
using namespace std;

void MaxProfit(int *prices,int n){
    int BestBuy[100000];

    BestBuy[0]=INT_MAX;

    for(int i=1;i<n;i++){
        BestBuy[i]=min(BestBuy[i-1],prices[i-1]);
    }

    int MaxProfit=0;

    for(int i=0;i<n;i++){
        int currprofit=prices[i]-BestBuy[i];
        MaxProfit=max(MaxProfit,currprofit);
    }

    cout<<"max profit = "<<MaxProfit ;
}

int main(){
    int prices[6]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(int);

    MaxProfit(prices,n);
    
    return 0;
}