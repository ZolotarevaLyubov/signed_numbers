#include <iostream>
#include <cmath>

using namespace std;


class Integer {
    private:
        unsigned int a;
        unsigned int b;
    
    public:
        Integer(int m, int n) : a(m), b(n) {}
        
        Integer(int num) {
            if(num > 0) {
                a = num;
                b = 0;
            }
            else if(num < 0) {
                a = 0;
                b = abs(num);
            }
            else {
                a = 0;
                b = 0;
            }    
        }
        
        int to_int() {
            return  a - b;
        }
        
        void Cout() const {
            cout << "Pair: " << a << "\\" << b << endl; 
        }
        
        bool operator == (const Integer& other) const {
            return (a + other.b) == (other.a + b);
        }
        
        Integer operator + (const Integer& other) const {
            return Integer (a + other.a, b + other.b);
        }
        
        Integer operator - (const Integer& other) const {
            return Integer (a + other.b, b + other.a);
        }
        
        Integer operator * (const Integer& other) const {
            return Integer (a * other.a + b * other.b, a * other.b + b * other.a);
        }

};

int main() {

    Integer num1(-7);
    Integer num2(-8);
    
    //num1.Cout();
    //num2.Cout();
    
    //equal
    /*
    if(num1 == num2){
        cout << "equal" <<endl;
    }
    else
        cout << "not equal" <<endl;
    */
    
    // +
    cout << "Num1 + Num2 = " << (num1 + num2).to_int() <<endl;
    
    // -
    cout << "Num1 - Num2 = " << (num1 - num2).to_int() <<endl;
    
    // *
    cout << "Num1 * Num2 = " << (num1 * num2).to_int() <<endl;
    
    //Integer num3(-13);
    //num3.Cout();
    //cout << num3.to_int() << endl;
    
    return 0;
}