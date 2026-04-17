# Arithmetic Expression Parser using YACC

## Description
This program uses YACC (Bison) to parse arithmetic expressions based on defined grammar rules.

## Steps to Run

### 1. Create the YACC file using vi
```bash
vi calc.y
````

* Press `i` to enter insert mode
* Write your YACC program
* Press `Esc`, then type `:wq` and hit Enter

### 2. Generate parser using Bison

```bash
bison -dy calc.y
```

### 3. Compile the generated file

```bash
gcc y.tab.c -o calc
```

### 4. Run the program

```bash
./calc
```

## Example

**Input:**

```
2+3
```

**Output:**

```
Add
```

## Notes

* `y.tab.c` is the generated parser file
* `y.tab.h` contains token definitions

