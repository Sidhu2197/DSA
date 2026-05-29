// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // void explainvector(){

// //     vector<int>v;//{}
// //     v.push_back(1);//{1}
// //     v.emplace_back(2);//{1,2}

// //     vector<int>v1(5,20);
// //     vector<int>v2(v1);

// // }

// void explainvector() {
//     vector<int> v;
//     v.push_back(1);
//     v.emplace_back(2);

//     for(auto it:v){
//         cout<<it<<" ";
//     }

//     // for (int i = 0; i < v.size(); i++) {
//     //     cout << v[i] << " ";
//     // }
//     // cout << endl;
// }


// int main() {
//     explainvector();
    
//     return 0;
// }






// // #include<iostream>
// // #include<vector>
// // using namespace std;

// // int main(){
// //     vector<int>vec1;
// //     cout<<vec1.size()<<"\n";
// //     return 0;
// // }



#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec={1,2,3,4};
    cout<<"size"<<":"<<vec.size()<<endl;//4
    cout<<"capacity"<<":"<<vec.capacity()<<endl;//4

    vec.push_back(5);
    cout<<"size"<<":"<<vec.size()<<endl;//5
    cout<<"capacity"<<":"<<vec.capacity()<<endl;//8

    vec.pop_back();
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;

    


}