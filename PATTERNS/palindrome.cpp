#include <iostream>
#include<string.h>
using namespace std;

bool ispalindrome(char str[], int n){
    int st=0,end=n-1;
    while(st<end){
        if(str[st++]!=str[end--]){
            cout<<"not a valid plaindrome\n";
            return false;
        }

    }
    cout<<"valid plaindrome\n";
    return true;

}

int main() {
    char word[10];
    cin>>word;
    ispalindrome(word,strlen(word));
    
    return 0;
}