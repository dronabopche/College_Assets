# AES Encryption and Decryption using OpenSSL (ECB Mode)

## Aim
To encrypt and decrypt a text file using AES-256 in ECB mode with OpenSSL.

---

## Create Text File

```txt
This is a secret message
```

Save as `plain.txt`

---

## Encryption Command

```bash
openssl enc -aes-256-ecb -in plain.txt -out encrypted.bin -k mypassword
```

---

## Decryption Command

```bash
openssl enc -d -aes-256-ecb -in encrypted.bin -out decrypted.txt -k mypassword
```

---

## View Decrypted File

```bash
cat decrypted.txt
```

---

## Result
The text file was successfully encrypted and decrypted using AES-256 in ECB mode with OpenSSL.