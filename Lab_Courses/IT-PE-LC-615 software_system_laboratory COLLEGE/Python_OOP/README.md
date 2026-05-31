# Python OOP Programs – How to Execute

## Prerequisites
Python 3 must be installed:
```bash
python3 --version
# If not installed:
sudo apt install python3
```

---

## Programs

| # | File | Description |
|---|------|-------------|
| 33 | `33_complex_numbers.py`              | Add complex numbers + operator overloading |
| 34 | `34_area_of_shapes.py`               | Area of shapes using polymorphism |
| 35 | `35_inheritance_and_string_concat.py`| Inheritance + string concatenation |

---

## How to Run Each Program

```bash
# 33 – Complex Number Addition (Operator Overloading)
python3 33_complex_numbers.py
# Output: Sum: 4 + 6i

# 34 – Area of Shapes (Polymorphism)
python3 34_area_of_shapes.py
# Output:
#   Circle area = 78.54
#   Rectangle area = 24.00
#   Triangle area = 12.00

# 35 – Inheritance + String Concatenation
python3 35_inheritance_and_string_concat.py
# Output:
#   Rex says Woof!
#   Whiskers says Meow!
#   Simple concat: Hello World
#   Multiple concat: Python is fun
#   Multilevel: foobarbaz
```

---

## Concepts Covered

### Program 33 – Operator Overloading
- `__add__` dunder method lets you use `+` between custom objects.
- `__str__` dunder method defines how the object prints.

### Program 34 – Polymorphism
- A base class `Shape` defines a common `area()` interface.
- Each subclass (`Circle`, `Rectangle`, `Triangle`) overrides `area()`.
- Calling `s.area()` on each shape calls the right version automatically.

### Program 35 – Inheritance & String Concatenation
- `Dog` and `Cat` inherit from `Animal` and override `speak()`.
- String concat methods shown: `+` operator, `"".join()`, and chained `+`.

---

## Notes
- All values are hardcoded; edit the source files to test with different inputs.
- No external libraries needed except Python's built-in `math` module (Program 34).
