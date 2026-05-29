#include<iostream>
#include<climits>
using namespace std;

int trap(int *heights,int n){
    int LeftMax[20000],RightMax[20000];
    LeftMax[0]=heights[0];
    RightMax[n-1]=heights[n-1];

    // Build left max
    for(int i=1;i<n;i++){
        LeftMax[i]=max(LeftMax[i-1],heights[i]); // ✅ fixed
    }

    // Build right max
    for(int i=n-2;i>=0;i--){
        RightMax[i]=max(RightMax[i+1],heights[i]); // ✅ fixed
    }

    int WaterTrapped=0;

    for(int i=0;i<n;i++){
        int currwater=min(LeftMax[i],RightMax[i])-heights[i];
        if(currwater>0){
            WaterTrapped+=currwater;
        }
    }

    return WaterTrapped; // ✅ fixed
}

int main(){
    int heights[5]={5,4,3,2,1};
    int n=sizeof(heights)/sizeof(int);

    cout << "Total Water Trapped = " << trap(heights,n) << endl; // ✅ fixed
}
