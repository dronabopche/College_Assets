# Function to calculate Index of Coincidence
def index_of_coincidence(text):
    # Convert to uppercase and remove spaces
    text = text.upper()
    text_no_space = ""
    for i in range(len(text)):
        if text[i] != " ":
            text_no_space += text[i]

    # Frequency array for A-Z
    freq = [0] * 26
    n = 0  # total letters

    # Count frequencies
    for i in range(len(text_no_space)):
        c = text_no_space[i]
        if c >= 'A' and c <= 'Z':
            index = ord(c) - ord('A')
            freq[index] += 1
            n += 1

    if n < 2:
        return 0.0

    total = 0
    for i in range(26):
        total += freq[i] * (freq[i] - 1)

    ic = total / (n * (n - 1))
    return ic

# Main program
plain = input("Enter plaintext: ")
cipher = input("Enter Vigenere ciphertext: ")

ic_plain = index_of_coincidence(plain)
ic_cipher = index_of_coincidence(cipher)

print("IC of plaintext:", ic_plain)
print("IC of ciphertext:", ic_cipher)

