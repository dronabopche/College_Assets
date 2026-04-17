## Steps to Run

### 1. Create the Lex file using vi
```bash
vi abc.l
````

* Press `i` to enter insert mode
* Write your Lex program
* Press `Esc`, then type `:wq` and hit Enter

### 2. Generate the C file using Lex

```bash
lex abc.l
```

### 3. Compile the generated file

```bash
gcc lex.yy.c -o abc
```

### 4. Run the program

```bash
./a.out
```


