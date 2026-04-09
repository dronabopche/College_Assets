# Generate 5x5 matrix from key
def generate_matrix(key):
    key = key.upper().replace("J", "I")

    seen = []
    for i in range(len(key)):
        c = key[i]
        if c not in seen and c != "J":
            seen.append(c)

    abc = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    for i in range(len(abc)):
        c = abc[i]
        if c not in seen:
            seen.append(c)

    matrix = []
    for i in range(5):
        row = []
        for j in range(5):
            row.append(seen[i*5 + j])
        matrix.append(row)

    return matrix

# Find position of character in matrix
def find_pos(matrix, c):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == c:
                return i, j
    return -1, -1  # Not found

# Encrypt plaintext using Playfair
def playfair_encrypt(plain, key):
    plain = plain.upper().replace("J", "I").replace(" ", "")

    # Add padding if length is odd
    if len(plain) % 2 != 0:
        plain += "X"

    matrix = generate_matrix(key)
    result = ""

    i = 0
    while i < len(plain):
        a = plain[i]
        b = plain[i+1]

        r1, c1 = find_pos(matrix, a)
        r2, c2 = find_pos(matrix, b)

        if r1 == r2:
            result += matrix[r1][(c1+1)%5]
            result += matrix[r2][(c2+1)%5]
        elif c1 == c2:
            result += matrix[(r1+1)%5][c1]
            result += matrix[(r2+1)%5][c2]
        else:
            result += matrix[r1][c2]
            result += matrix[r2][c1]

        i += 2

    return result

# Decrypt ciphertext using Playfair
def playfair_decrypt(cipher, key):
    matrix = generate_matrix(key)
    result = ""

    i = 0
    while i < len(cipher):
        a = cipher[i]
        b = cipher[i+1]

        r1, c1 = find_pos(matrix, a)
        r2, c2 = find_pos(matrix, b)

        if r1 == r2:
            result += matrix[r1][(c1-1)%5]
            result += matrix[r2][(c2-1)%5]
        elif c1 == c2:
            result += matrix[(r1-1)%5][c1]
            result += matrix[(r2-1)%5][c2]
        else:
            result += matrix[r1][c2]
            result += matrix[r2][c1]

        i += 2

    return result

# Main program
plain = input("Enter plaintext: ")
key = input("Enter key: ")

cipher = playfair_encrypt(plain, key)
print("Encrypted:", cipher)

decrypted = playfair_decrypt(cipher, key)
print("Decrypted:", decrypted)

