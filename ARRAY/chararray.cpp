#include <iostream>
#include<cstring>
using namespace std;
int main() {
    

    char sentence[30];
    cin.getline(sentence,30);

    cout<<"word is :"<<sentence<<endl;
    cout<<"length of the word is "<<strlen(sentence)<<endl;
    return 0;
}
