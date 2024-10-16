class SignedInt:
    def __init__(self, num):
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
            if i < len(number) - 1 and ((number[]))                      
                