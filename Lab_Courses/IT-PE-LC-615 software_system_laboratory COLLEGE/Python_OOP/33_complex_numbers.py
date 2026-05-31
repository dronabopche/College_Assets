# Complex Number Addition with Operator Overloading
class Complex:
    def __init__(self, r, i):
        self.r = r
        self.i = i

    def __add__(self, other):
        return Complex(self.r + other.r, self.i + other.i)

    def __str__(self):
        return f"{self.r} + {self.i}i"

c1 = Complex(3, 4)
c2 = Complex(1, 2)
print("Sum:", c1 + c2)
