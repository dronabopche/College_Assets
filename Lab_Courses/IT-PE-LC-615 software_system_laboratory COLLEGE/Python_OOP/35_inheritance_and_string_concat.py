# Inheritance
class Animal:
    def __init__(self, name):
        self.name = name
    def speak(self):
        return "..."

class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"

d = Dog("Rex")
c = Cat("Whiskers")
print(d.speak())
print(c.speak())

# String Concatenation – Simple
s1 = "Hello"
s2 = " World"
print("Simple concat:", s1 + s2)

# Multiple concatenation
parts = ["Python", " is", " fun"]
print("Multiple concat:", "".join(parts))

# Multilevel concatenation
level1 = "foo" + "bar"
level2 = level1 + "baz"
print("Multilevel:", level2)
