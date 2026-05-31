# Area of Shapes using Polymorphism
import math

class Shape:
    def area(self):
        return 0

class Circle(Shape):
    def __init__(self, r):
        self.r = r
    def area(self):
        return math.pi * self.r ** 2

class Rectangle(Shape):
    def __init__(self, l, b):
        self.l = l
        self.b = b
    def area(self):
        return self.l * self.b

class Triangle(Shape):
    def __init__(self, b, h):
        self.b = b
        self.h = h
    def area(self):
        return 0.5 * self.b * self.h

shapes = [Circle(5), Rectangle(4, 6), Triangle(3, 8)]
for s in shapes:
    print(f"{s.__class__.__name__} area = {s.area():.2f}")
