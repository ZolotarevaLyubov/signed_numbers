/**
      +
      -
      *

      ||||||

      IT

      IIITT = 1
      ITTT = -2
      IT = 
      TI =

      TIIITI = II
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class SignedInt {
private:
    string number;
    
public:
    SignedInt(int num) {
         char a = num > 0? 'I' : 'T';
         for(int i = 0; i < abs(num); i++) {
             number.push_back(a);
         }
    }
    int conversion() {
         int result = 0;
         for(int i = 0; i < number.size(); i++) {
             result += number.at(i) == 'I'? 1 : -1;
         }
         
         return result;
    }    
};

string reduce(string number) {
    bool changed;
        
    do {
        changed = false;
        string new_number;
    
        //не (a и b) = (не a) или (не b)
        //не (a или b) = (не a) и (не b)
    
    
        for(int i = 0; i < number.size(); i++) {
            if(number.at(i) != 'I' && number.at(i) != 'T') {
                cerr << "invalid string: reduce()" <<endl;
            }
        
            if(i == number.size()-1) {
                new_number.push_back(number.at(i));
                continue;
            }
        
            if(number.at(i) == 'I' && number.at(i+1) == 'T') {
                i++;
                changed = true;
                continue;
            }
            else if(number.at(i) == 'T' && number.at(i+1) == 'I') {
                i++;
                changed = true;
                continue;
            }
        
            new_number.push_back(number.at(i));
        }
        
        number = new_number;   
    
        cout << "Number: " << number << endl; 
        
    }while(changed);    
        
    return number;    
}

int main() {

    // cout << "Reduce result: " << reduce("IIIIITTTTTI") <<endl;
    SignedInt number(0);
    cout << "Int number: " << number.conversion() << endl;  
}