## 📄 Create a New File

To create a new empty file:

```bash
touch filename.c
```

For a text file:

```bash
touch filename.txt
```

---

## ✏️ Edit File Using `vi`

Open a file in the `vi` editor:

```bash
vi filename.c
```

### Save and Exit:

1. Press `Esc`
2. Type `:wq`
3. Press `Enter`

---

## ⚙️ Compile the C Program

Use the `cc` compiler:

```bash
cc filename.c
```

This generates an executable file (default: `a.out`).

---

## ▶️ Run the Program

```bash
./a.out
```

---

## 📌 Example Workflow

```bash
touch hello.c
vi hello.c
cc hello.c
./a.out
```

---

## 📝 Notes

* Make sure C compiler is installed (`gcc` or `cc`)
* Use proper file extensions (`.c` for C programs)
* Always save (`:wq`) before compiling


