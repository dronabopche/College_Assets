# RSA Encryption and Decryption Using OpenSSL

## Aim

To encrypt and decrypt a message using RSA algorithm with OpenSSL.

---

# Introduction

RSA is an asymmetric encryption algorithm that uses:

* **Public Key** → Encryption
* **Private Key** → Decryption

Data encrypted with the public key can only be decrypted using the corresponding private key.

---

# Requirements

* OpenSSL installed
* RSA public and private keys generated

Check OpenSSL version:

```bash id="5v5c25"
openssl version
```

---

# Step 1: Generate RSA Private Key

```bash id="14n0kg"
openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:2048
```

---

# Step 2: Generate RSA Public Key

```bash id="0ucjlwm"
openssl rsa -pubout -in private_key.pem -out public_key.pem
```

---

# Step 3: Create a Message File

Create a plaintext file named `message.txt`

```text id="c3m4ud"
Hello, this is a secret RSA message.
```

Or create using terminal:

```bash id="ef7g2m"
echo "Hello, this is a secret RSA message." > message.txt
```

---

# Step 4: Encrypt the Message Using Public Key

## Command

```bash id="9u9azm"
openssl pkeyutl -encrypt \
-pubin -inkey public_key.pem \
-in message.txt \
-out encrypted.bin
```

---

## Explanation

| Option                  | Meaning             |
| ----------------------- | ------------------- |
| `pkeyutl`               | Public key utility  |
| `-encrypt`              | Encryption mode     |
| `-pubin`                | Input is public key |
| `-inkey public_key.pem` | Public key file     |
| `-in message.txt`       | Plaintext message   |
| `-out encrypted.bin`    | Encrypted output    |

---

# Step 5: View Encrypted Data

```bash id="fiyjqx"
xxd encrypted.bin
```

or

```bash id="sud17s"
hexdump -C encrypted.bin
```

---

# Step 6: Decrypt the Message Using Private Key

## Command

```bash id="wrrm4c"
openssl pkeyutl -decrypt \
-inkey private_key.pem \
-in encrypted.bin \
-out decrypted.txt
```

---

## Explanation

| Option                   | Meaning          |
| ------------------------ | ---------------- |
| `-decrypt`               | Decryption mode  |
| `-inkey private_key.pem` | Private key file |
| `-in encrypted.bin`      | Encrypted file   |
| `-out decrypted.txt`     | Decrypted output |

---

# Step 7: View Decrypted Message

```bash id="yhv60t"
cat decrypted.txt
```

---

# Sample Output

## Original Message

```text id="lcl7nc"
Hello, this is a secret RSA message.
```

---

## Encrypted Output

```text id="7g6h0z"
3f 7a a2 91 5c 84 ...
```

(Binary encrypted data)

---

## Decrypted Message

```text id="7bzxtt"
Hello, this is a secret RSA message.
```

---

# Verification

Compare original and decrypted messages:

```bash id="v9bfvm"
cat message.txt
cat decrypted.txt
```

Both outputs should match.

---

# Result

The message was successfully encrypted using the RSA public key and decrypted using the RSA private key.

---

# Conclusion

* RSA encryption was successfully performed using OpenSSL.
* The public key encrypted the message securely.
* The private key correctly decrypted the ciphertext.
* RSA ensures confidentiality and secure communication.
