# Define S-box as a list (like an array in C)
sbox = [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7]

# Create a 16x16 table
table = []
for i in range(16):
    row = []
    for j in range(16):
        value = sbox[i] ^ sbox[j]   # XOR, same as C's ^
        row.append(value)
    table.append(row)

# Print the table
for i in range(16):
    for j in range(16):
        # Print like "%2d "
        print(f"{table[i][j]:2d}", end=" ")
    print()
