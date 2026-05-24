# Generating RSA Public and Private Key Pairs Using OpenSSL

## Aim

To generate RSA public and private key pairs using OpenSSL.

---

# Introduction

RSA is an asymmetric cryptographic algorithm used for:

* Secure communication
* Digital signatures
* Encryption and decryption

RSA uses:

* **Public Key** → Used for encryption
* **Private Key** → Used for decryption

OpenSSL provides commands to generate RSA keys easily.

---

# Requirements

* OpenSSL installed on the system

Check installation:

```bash id="nh1th6"
openssl version
```

---

# Step 1: Generate RSA Private Key

## Command

```bash id="v7gm6d"
openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:2048
```

---

## Explanation

| Option                 | Meaning                 |
| ---------------------- | ----------------------- |
| `genpkey`              | Generates private key   |
| `-algorithm RSA`       | Specifies RSA algorithm |
| `-out private_key.pem` | Output private key file |
| `rsa_keygen_bits:2048` | Key size = 2048 bits    |

---

# Step 2: View the Private Key

```bash id="m0m9x3"
cat private_key.pem
```

---

# Step 3: Generate RSA Public Key

## Command

```bash id="z69ejw"
openssl rsa -pubout -in private_key.pem -out public_key.pem
```

---

## Explanation

| Option                | Meaning            |
| --------------------- | ------------------ |
| `rsa`                 | RSA utility        |
| `-pubout`             | Extract public key |
| `-in private_key.pem` | Input private key  |
| `-out public_key.pem` | Output public key  |

---

# Step 4: View the Public Key

```bash id="1mfrg6"
cat public_key.pem
```

---

# Generated Files

| File              | Description     |
| ----------------- | --------------- |
| `private_key.pem` | RSA Private Key |
| `public_key.pem`  | RSA Public Key  |

---

# Verify the RSA Key Pair

## Check Private Key Details

```bash id="2go2w6"
openssl rsa -in private_key.pem -text -noout
```

---

## Check Public Key Details

```bash id="e6g1ur"
openssl rsa -pubin -in public_key.pem -text -noout
```

---

# Sample Output

## Private Key

```text id="15s4c7"
-----BEGIN PRIVATE KEY-----
MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBK...
-----END PRIVATE KEY-----
```

---

## Public Key

```text id="0i4u8y"
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AM...
-----END PUBLIC KEY-----
```

---

# Result

RSA public and private key pairs were successfully generated using OpenSSL.

---

# Conclusion

* RSA private key was generated successfully.
* Public key was extracted from the private key.
* The generated keys can now be used for:

  * Encryption
  * Decryption
  * Digital signatures
  * Secure communication
