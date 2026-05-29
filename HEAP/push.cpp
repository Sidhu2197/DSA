#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;  //cbt and max heap
    
    public:

    void push(int val){
        //1
        vec.push_back(val);
        //2 fix heap
        int x=vec.size()-1;
        int pari=(x-1)/2;

        while(pari>=0 && vec[x]>vec[pari]){
            swap(vec[x],vec[pari]);
            x=pari;
            pari=(x-1)/2;
        }


    }

    void pop(){

    }

    int top(){
        return vec[0];//highest priority element

    }

    bool empty(){
        return vec.size()==0;
    }



};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout<<"top = "<<heap.top()<<endl;


    return 0;
}