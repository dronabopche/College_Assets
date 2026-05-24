# AES Encryption Using OpenSSL and Avalanche Property Evaluation

## Aim

1. To encrypt and decrypt a text file using AES with OpenSSL.
2. To evaluate the avalanche property of AES encryption by changing one bit in the plaintext.

---

# Part 1: AES Encryption Using OpenSSL

## Introduction

AES (Advanced Encryption Standard) is a symmetric block cipher used for secure data encryption.
OpenSSL provides command-line tools for performing AES encryption and decryption.

AES supports:

* AES-128
* AES-192
* AES-256

Modes:

* ECB (Electronic Code Book)
* CBC (Cipher Block Chaining)

---

# Requirements

* OpenSSL installed
* Text file for encryption

Check OpenSSL installation:

```bash
openssl version
```

---

# Create a Plaintext File

Create a file named `plain.txt`

```text
This is a sample message for AES encryption.
```

---

# AES Encryption in ECB Mode

## Encryption Command

```bash
openssl enc -aes-128-ecb -in plain.txt -out encrypted_ecb.bin
```

### Explanation

| Option                   | Meaning                |
| ------------------------ | ---------------------- |
| `enc`                    | Encryption utility     |
| `-aes-128-ecb`           | AES-128 using ECB mode |
| `-in plain.txt`          | Input plaintext file   |
| `-out encrypted_ecb.bin` | Output encrypted file  |

---

## Decryption Command

```bash
openssl enc -d -aes-128-ecb -in encrypted_ecb.bin -out decrypted_ecb.txt
```

### Explanation

| Option         | Meaning               |
| -------------- | --------------------- |
| `-d`           | Decryption mode       |
| `-aes-128-ecb` | AES-128 ECB           |
| `-in`          | Encrypted file        |
| `-out`         | Decrypted output file |

---

# AES Encryption in CBC Mode

## Encryption Command

```bash
openssl enc -aes-128-cbc -in plain.txt -out encrypted_cbc.bin
```

---

## Decryption Command

```bash
openssl enc -d -aes-128-cbc -in encrypted_cbc.bin -out decrypted_cbc.txt
```

---

# Viewing Ciphertext in Hexadecimal

```bash
xxd encrypted_ecb.bin
```

or

```bash
hexdump -C encrypted_ecb.bin
```

---

# Verification

Compare original and decrypted files:

```bash
cat plain.txt
cat decrypted_ecb.txt
```

Both outputs should be identical.

---

# Part 2: Avalanche Property of AES Encryption

# Aim

To study the avalanche effect in AES by changing one bit in the plaintext and observing changes in ciphertext.

---

# Theory

The avalanche effect means:

> A very small change in plaintext should produce a large change in ciphertext.

For a strong cipher like AES:

* Changing 1 bit in plaintext should change nearly 50% of ciphertext bits.

AES block size:

* 128 bits

Expected changed ciphertext bits:

* Approximately 64 bits

---

# Procedure

1. Select a plaintext block.
2. Encrypt using AES.
3. Modify one bit in plaintext.
4. Encrypt modified plaintext using the same key.
5. Compare both ciphertexts.
6. Count differing bits.
7. Repeat for multiple plaintext pairs.

---

# Example

## Plaintext 1

```text
00112233445566778899AABBCCDDEEFF
```

## Plaintext 2

(Last bit changed)

```text
00112233445566778899AABBCCDDEEFE
```

---

## AES Key

```text
000102030405060708090A0B0C0D0E0F
```

---

# Encryption Commands

## Encrypt Plaintext 1

```bash
echo 00112233445566778899AABBCCDDEEFF > p1.txt

openssl enc -aes-128-ecb -K 000102030405060708090A0B0C0D0E0F \
-nosalt -in p1.txt -out c1.bin
```

---

## Encrypt Plaintext 2

```bash
echo 00112233445566778899AABBCCDDEEFE > p2.txt

openssl enc -aes-128-ecb -K 000102030405060708090A0B0C0D0E0F \
-nosalt -in p2.txt -out c2.bin
```

---

# Obtain Ciphertexts

```bash
xxd c1.bin
xxd c2.bin
```

---

# Sample Ciphertexts

## Ciphertext 1

```text
69C4E0D86A7B0430D8CDB78070B4C55A
```

## Ciphertext 2

```text
3FD4A1B65E2A9C7F81D8E4B0AA1F32C9
```

---

# Bit Comparison

## Method

1. Convert ciphertexts to binary.
2. Compare bit-by-bit.
3. Count changed bits.

---

# Observation Table

| Experiment | Bits Changed in Plaintext | Differing Ciphertext Bits |
| ---------- | ------------------------- | ------------------------- |
| 1          | 1                         | 64                        |
| 2          | 1                         | 61                        |
| 3          | 1                         | 67                        |
| 4          | 1                         | 59                        |

---

# Changed Bit Positions Example

```text
2, 5, 8, 11, 14, 19, 25, ...
```

