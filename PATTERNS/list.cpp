void explainlist(){
    list<int> ls;
    ls.push_back(2);//{2}

    ls.emplace_back(4);//{2,4}

    ls.push_front(5);//{5,2,4c}
    ls.emplace_front();//{2,4}
}


#include <iostream>
#include<list>
using namespace std;
int main() {
    
    return 0;
}