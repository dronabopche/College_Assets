# Generating Message Digests Using SHA and MD5 Algorithms

## Aim

To generate message digests using SHA and MD5 algorithms with OpenSSL.

---

# Introduction

A message digest is a fixed-length hash value generated from input data.

Hash functions are used for:

* Data integrity
* Password storage
* Digital signatures
* Authentication

Common algorithms:

* MD5
* SHA-1
* SHA-256
* SHA-512

---

# Requirements

* OpenSSL installed

Check installation:

```bash id="9d5rde"
openssl version
```

---

# Step 1: Create a Message File

Create a file named `message.txt`

```text id="j0th8n"
Hello World
```

Or using terminal:

```bash id="v30n8y"
echo "Hello World" > message.txt
```

---

# Part A: Generate MD5 Message Digest

## Command

```bash id="dzujpc"
openssl dgst -md5 message.txt
```

---

## Explanation

| Option        | Meaning               |
| ------------- | --------------------- |
| `dgst`        | Digest utility        |
| `-md5`        | MD5 hashing algorithm |
| `message.txt` | Input file            |

---

## Sample Output

```text id="qvw5g0"
MD5(message.txt)= b10a8db164e0754105b7a99be72e3fe5
```

---

# Part B: Generate SHA-1 Message Digest

## Command

```bash id="qpcxhz"
openssl dgst -sha1 message.txt
```

---

## Sample Output

```text id="6v5t7y"
SHA1(message.txt)= 0a4d55a8d778e5022fab701977c5d840bbc486d0
```

---

# Part C: Generate SHA-256 Message Digest

## Command

```bash id="kw11tb"
openssl dgst -sha256 message.txt
```

---

## Sample Output

```text id="gwhnno"
SHA256(message.txt)= a591a6d40bf420404a011733cfb7b190...
```

---

# Part D: Generate SHA-512 Message Digest

## Command

```bash id="7js5gx"
openssl dgst -sha512 message.txt
```

---

## Sample Output

```text id="xyjlwm"
SHA512(message.txt)= 2c74fd17edafd80e8447b0d46741ee24...
```

---

# Comparison of Algorithms

| Algorithm | Digest Size | Security    |
| --------- | ----------- | ----------- |
| MD5       | 128 bits    | Weak        |
| SHA-1     | 160 bits    | Weak        |
| SHA-256   | 256 bits    | Strong      |
| SHA-512   | 512 bits    | Very Strong |

---

# Verification of File Integrity

If file content changes even slightly:

* The hash value changes completely.

Example:

* Original: `Hello World`
* Modified: `hello world`

Both produce completely different digests.

---

# Result

Message digests were successfully generated using:

* MD5
* SHA-1
* SHA-256
* SHA-512 algorithms.

---

# Conclusion

* Hash functions generate fixed-length digests from input data.
* MD5 and SHA algorithms were successfully implemented using OpenSSL.
* SHA-256 and SHA-512 provide stronger security than MD5 and SHA-1.
* Message digests help ensure data integrity and authentication.
