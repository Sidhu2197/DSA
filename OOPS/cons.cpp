#include<iostream>
#include<string>
using namespace std;

class user{
    
    private:
    int id;
    string password;

    public:
    string username;

    // constructor with all 3 parameters
    user(int id,string password,string username)
    {
        this->id = id;
        this->password = password;
        this->username = username;
    }

    // constructor with only id
    user(int id)
    {
        this->id = id;
        this->password = "";
        this->username = "";
    }

    //getter
    string getpassword(){
        return password;
    }

    //setter
    void setpassword(string password){
        this->password = password;
    }

};

int main(){
    // Using constructor with only id
    user user1(55);
    user1.username = "meow";
    user1.setpassword("hi car");

    cout << "User1 Username: " << user1.username << endl;
    cout << "User1 Password: " << user1.getpassword() << endl;

    // Using constructor with all parameters
    user user2(101, "cat123", "whiskers");

    // Using default copy constructor (compiler provides it)
    user user3(user1);

    cout << "User2 Username: " << user2.username << endl;
    cout << "User2 Password: " << user2.getpassword() << endl;

    cout << "User3 Username: " << user3.username << endl;
    cout << "User3 Password: " << user3.getpassword() << endl;
}
