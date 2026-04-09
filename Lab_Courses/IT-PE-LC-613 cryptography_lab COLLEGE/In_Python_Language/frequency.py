def frequency(text):
    freq = {}
    for c in text.upper():
        if c.isalpha():
            if c in freq:
                freq[c] += 1
            else:
                freq[c] = 1

    result = []
    for letter in sorted(freq):
        result.append([letter, freq[letter]])
    return result


text = input("Enter cipher text: ")
for letter, count in frequency(text):
    print([letter, count])
