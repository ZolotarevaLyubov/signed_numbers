#include <iostream>

using namespace std;


class Integer {
    private:
        int a;
        int b;
    
    public:
        Integer(int m, int n) : a(m), b(n) {}
        
        void Cout() const {
            cout << "Pair: " << a << "\\" << b << endl; 
        }
        
        bool operator == (const Integer& other) const {
            return (a + other.b) == (other.a + b);
        }
        
        int operator + (const Integer& other) const {
            return (a + other.a) - (b + other.b);
        }
        
        int operator - (const Integer& other) const {
            return (a + other.b) - (b + other.a);
        }
        
        int operator * (const Integer& other) const {
            return (a * other.a + b * other.b) - (a * other.b + b * other.a);
        }

};

int main() {

    Integer num1(7,3);
    Integer num2(8,1);
    
    num1.Cout();
    num2.Cout();
    
    //equal
    if(num1 == num2){
        cout << "equal" <<endl;
    }
    else
        cout << "not equal" <<endl;
    
    
    // +
    cout << "Num1 + Num2 = " << num1 + num2 <<endl;
    
    // -
    cout << "Num1 - Num2 = " << num1 - num2 <<endl;
    
    // *
    cout << "Num1 * Num2 = " << num1 * num2 <<endl;
    
    return 0;
}