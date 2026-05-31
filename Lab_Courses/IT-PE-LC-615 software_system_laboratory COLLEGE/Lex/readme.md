# LEX Programs – How to Execute

## Prerequisites
Install flex (the modern lex):
```bash
sudo apt install flex
```

---

## Programs

### 1. Valid Integer Constant (`1_valid_integer.l`)
Recognizes valid integer inputs.

```bash
flex 1_valid_integer.l
gcc lex.yy.c -o valid_integer -lfl
echo "12345" | ./valid_integer
echo "abc" | ./valid_integer
```

---

### 2. Valid Identifier (`2_valid_identifier.l`)
Recognizes valid C-style identifiers.

```bash
flex 2_valid_identifier.l
gcc lex.yy.c -o valid_identifier -lfl
echo "myVar_1" | ./valid_identifier
echo "123abc" | ./valid_identifier
```

---

### 3. Valid Float Constant (`3_valid_float.l`)
Recognizes valid floating-point numbers.

```bash
flex 3_valid_float.l
gcc lex.yy.c -o valid_float -lfl
echo "3.14" | ./valid_float
echo "abc" | ./valid_float
```

---

## General Compile Steps (for any .l file)
```bash
flex <filename>.l          # generates lex.yy.c
gcc lex.yy.c -o <output> -lfl
echo "<input>" | ./<output>
```

## Notes
- `-lfl` links the flex library. On some systems use `-ll` instead.
- Press `Ctrl+D` to send EOF when running interactively.
- `yytext` holds the matched token text.
