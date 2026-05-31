# YACC Programs – How to Execute

## Prerequisites
Install flex and bison (the modern yacc):
```bash
sudo apt install flex bison
```

---

## Programs

### 4. Calculator (`calc.l` + `calc.y`)
Supports `+`, `-`, `*`, `/` operations.

```bash
lex calc.l              # generates lex.yy.c
yacc -d calc.y          # generates y.tab.c and y.tab.h
gcc lex.yy.c y.tab.c -o calc -lfl
echo "3+4" | ./calc
echo "10*2" | ./calc
echo "15/3" | ./calc
```

---

### 5. Arithmetic Expression (`arith.l` + `arith.y`)
Supports only `+`, `-`, `*` operations (no division).

```bash
lex arith.l
yacc -d arith.y
gcc lex.yy.c y.tab.c -o arith -lfl
echo "3+4*2" | ./arith
echo "10-5+3" | ./arith
```

---

## General Compile Steps
```bash
lex <lexer>.l            # Step 1: generate lex.yy.c
yacc -d <parser>.y       # Step 2: generate y.tab.c + y.tab.h
gcc lex.yy.c y.tab.c -o <output> -lfl   # Step 3: compile
echo "<expression>" | ./<output>         # Step 4: run
```

## Notes
- `-d` flag in yacc generates `y.tab.h` (needed by the lexer).
- On some systems use `-ly` instead of `-lfl` for yacc programs.
- If `lex` is not found, use `flex` instead.
- If `yacc` is not found, use `bison -y` instead.
- Press `Ctrl+D` to exit interactive mode.
