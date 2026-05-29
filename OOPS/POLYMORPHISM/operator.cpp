#include<iostream>
#include<string>
using namespace std;

class Complex{
    int real;
    int img;
    
public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    
    void Show(){
        cout << real << "+" << img << "i" << endl;
    }
    
    // Fixed operator overloading - should return Complex object
    Complex operator - (Complex &c2){
        int real_result = this->real - c2.real;
        int img_result = this->img - c2.img;
        Complex c3(real_result, img_result);
        return c3;  // Return the result object
    }
};

int main(){
    Complex c1(1, 2);
    Complex c2(3, 4);
    
    c1.Show();  // Output: 1+2i
    c2.Show();  // Output: 3+4i
    
    // Now we can actually use the + operator
    Complex c3 = c1 - c2;
    cout << "Result = ";
    c3.Show();  // Output: Result = 4+6i
    
    return 0;
}