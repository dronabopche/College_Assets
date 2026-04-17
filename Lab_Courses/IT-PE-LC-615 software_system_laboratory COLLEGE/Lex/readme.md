# Alphanumeric Validation using Lex

## Description
This program uses Lex to check whether the given input is alphanumeric.

## Steps to Run

### 1. Create the Lex file using vi
```bash
vi alphanumeric.l
````

* Press `i` to enter insert mode
* Write your Lex program
* Press `Esc`, then type `:wq` and hit Enter

### 2. Generate the C file using Lex

```bash
lex alphanumeric.l
```

### 3. Compile the generated file

```bash
gcc lex.yy.c -o alphanumeric
```

### 4. Run the program

```bash
./a.out
```

## Example

**Input:**

```
abc123
```

**Output:**

```
Valid Alphanumeric
```

