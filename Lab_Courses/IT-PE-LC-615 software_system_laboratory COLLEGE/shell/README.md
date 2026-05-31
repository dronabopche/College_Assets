# Shell Programs – How to Execute

## Prerequisites
Bash is pre-installed on Linux/macOS. For Windows, use Git Bash or WSL.

Make a script executable before running it:
```bash
chmod +x <script_name>.sh
```

---

## Programs

| # | File | Description |
|---|------|-------------|
| 6  | `06_hello_world.sh`         | Prints Hello World |
| 7  | `07_add_two_numbers.sh`     | Adds 2 user-input numbers |
| 8  | `08_average_five_numbers.sh`| Average of 5 numbers |
| 9  | `09_greater_of_two.sh`      | Greater of 2 numbers |
| 10 | `10_greatest_of_three.sh`   | Greatest of 3 numbers |
| 11 | `11_factorial.sh`           | Factorial of N |
| 12 | `12_sum_upto_n.sh`          | Sum of 1 to N |
| 13 | `13_palindrome.sh`          | Palindrome check |
| 14 | `14_prime.sh`               | Prime number check |
| 15 | `15_fibonacci.sh`           | Fibonacci series |
| 16 | `16_max_min_array.sh`       | Max & Min of array |
| 17 | `17_linear_search.sh`       | Linear search in array |
| 18 | `18_bubble_sort.sh`         | Bubble sort |
| 19 | `19_matrix_multiplication.sh` | 2x2 Matrix multiplication |
| 20 | `20_sum_array.sh`           | Sum of all array elements |

---

## How to Run Each Program

```bash
# 6 – Hello World
./06_hello_world.sh

# 7 – Add Two Numbers
./07_add_two_numbers.sh

# 8 – Average of Five Numbers
./08_average_five_numbers.sh

# 9 – Greater of Two Numbers
./09_greater_of_two.sh

# 10 – Greatest of Three Numbers
./10_greatest_of_three.sh

# 11 – Factorial
./11_factorial.sh

# 12 – Sum up to N
./12_sum_upto_n.sh

# 13 – Palindrome
./13_palindrome.sh

# 14 – Prime Number
./14_prime.sh

# 15 – Fibonacci Series
./15_fibonacci.sh

# 16 – Max & Min in Array
./16_max_min_array.sh

# 17 – Linear Search
./17_linear_search.sh

# 18 – Bubble Sort
./18_bubble_sort.sh

# 19 – Matrix Multiplication (2x2)
./19_matrix_multiplication.sh

# 20 – Sum of Array Elements
./20_sum_array.sh
```

---

## Notes
- Program 8 requires `bc` for decimal division: `sudo apt install bc`
- All scripts use `#!/bin/bash` shebang — run with `bash` if needed: `bash <script>.sh`
- Scripts 16–20 have hardcoded arrays; edit the `arr=(...)` line to change values.
