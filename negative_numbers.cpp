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


string reduce(string number);

class SignedInt {
private:

    
public:
    string number;

    SignedInt(int num) {
         char a = num > 0? 'I' : 'T';
         for(int i = 0; i < abs(num); i++) {
             number.push_back(a);
         }
    }
    
    SignedInt(string num) {
         for(int i = 0; i < num.size(); i++) {
              if(num.at(i) != 'I' && num.at(i) != 'T') {
                   throw invalid_argument("I or T");
              }
         }
         number = num;
    }
    
    int conversion() const {//const потому что метод не изменяет объект
         int result = 0;
         for(int i = 0; i < number.size(); i++) {
             result += number.at(i) == 'I'? 1 : -1;
         }
         
         return result;
    }    
    
    SignedInt operator + (const SignedInt& other) {
        return SignedInt (reduce(this->number + other.number));
    
    }
    
    SignedInt operator - (const SignedInt& other) {
        string result = other.number;
        
        for(int i = 0; i < other.number.size(); i++) {
            result.at(i) = other.number.at(i) == 'I'? 'T' : 'I';
        }
        return SignedInt (reduce(this->number + result));
    }
    
    SignedInt operator * (const SignedInt& other) {
        string result = string(abs(this->conversion()) * abs(other.conversion()), 'I');
        
        
    }
    
};


//[TTT] +  [TT] = [TTTTT] = -5
//[TT] + [III] = [TTIII] = [TII] = [I] = 1
//[IIII] - [II] = [IIII] + [TT] = [IIIITT] = [IIIT] = [II] = 2
//[TTTT] - [TT] = [TTTT] + [II] = [TTTTII] = [TTTI] = [TT] = -2
  //-4   - -2  = -2


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
    SignedInt number1(-8);
    //cout << "Int number: " << number.conversion() << endl; 
    SignedInt number2(-2);
    SignedInt result = number1 - number2;
    cout << "RESULT:: " <<  result.conversion() << endl;
    //cout << result; // перегрузить <<    [IIITTTT]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}