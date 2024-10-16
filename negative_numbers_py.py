class SignedInt:
    def __init__(self, num):
        if isinstance(num, str):
            self.number = reduce(num)
        else:    
            self.number = 'I' * abs(num) if num > 0 else 'T' * abs(num)
        
    def conversion(self):
        result = sum(1 if ch == 'I' else -1 for ch in self.number)
        return result    
        
    def size(self):
        return len(self.number)
        
    def at(self, i):
        return self.number[i]        
        
    def __add__(self, other):
        return SignedInt(reduce(self.number + other.number))
        
    def __sub__(self, other):
        result = ''.join('T' if ch == 'I' else 'I' for ch in other.number)
        return SignedInt(reduce(self.number + result))
        
    def __mul__(self, other):
        result = ''
        for ch1 in self.number:
            for ch2 in other.number:
                if ch1 == 'I' and ch2 == 'I':
                    result += 'I'
                elif ch1 == 'T' and ch2 == 'T':
                    result += 'I'
                else:
                    result += 'T'
        return SignedInt(reduce(result))        
        
def reduce(number):
    changed = True
    while changed:
        changed = False
        new_number = ''
        i = 0
        while i < len(number):
            if i < len(number) - 1 and ((number[i] == 'I' and number[i + 1] == 'T') or (number[i] == 'T' and number[i + 1] == 'I')):
                i += 1
                changed = True
            else:
                new_number += number[i]
            i += 1
        number = new_number
    return number                                  

                
number1 = SignedInt(-8)
number2 = SignedInt(-2)    

addition_result = number1 + number2
subtraction_result = number1 - number2
multiplication_result = number1 * number2

addition_output = addition_result.conversion()
subtraction_output = subtraction_result.conversion()
multiplication_output = multiplication_result.conversion()

addition_output, subtraction_output, multiplication_output 

print("number1 + number2 = ", addition_output)

print("number1 - number2 = ", subtraction_output)

print("number1 * number2 = ", multiplication_output)



            