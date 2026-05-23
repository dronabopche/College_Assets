# Cryptography & Network Security Lab Question List

## Classical Cipher Programs

1. Program to encrypt and decrypt a text file using a Monoalphabetic Cipher.

2. Program to retrieve plaintext from a given ciphertext generated using a Monoalphabetic Cipher using Frequency Analysis Attack.

3. Program to encrypt and decrypt a text file using the Playfair Cipher (5×5 matrix).

4. Program to encrypt and decrypt a text file using the Playfair Cipher (16×16 matrix).

5. Program to encrypt and decrypt a text file using the Vigenère Cipher.

6. Program to calculate the Index of Coincidence (IC) of a given ciphertext file.

7. Program to determine whether a cipher is monoalphabetic or polyalphabetic using Index of Coincidence.

8. Program to retrieve plaintext from a ciphertext generated using a Vigenère Cipher using the Kasiski Test.

9. Program to estimate the key length of a Vigenère Cipher using Kasiski Examination and Index of Coincidence.

10. Program to find the modular inverse (a^{-1} \bmod n) using the Extended Euclidean Algorithm.

---

# OpenSSL Experiments

11. Encrypt and decrypt a text file using AES in ECB mode with OpenSSL.

12. Encrypt and decrypt a text file using AES in CBC mode with OpenSSL.

13. Compare AES ECB and CBC modes to demonstrate their security properties.

14. Evaluate the avalanche property of AES encryption:

* Encrypt plaintext blocks differing by one bit.
* Compare resulting ciphertexts.
* Count differing bits and identify changed positions.
* Repeat the experiment for multiple plaintext pairs.

15. Generate RSA public and private key pairs using OpenSSL.

16. Encrypt and decrypt a message using RSA.

17. Explain the parameters involved in RSA key generation.

18. Generate message digests using SHA and MD5 algorithms.

19. Analyze how a one-bit change in plaintext affects SHA and MD5 digests.

20. Generate a self-signed digital certificate using OpenSSL.

21. Explain the role and importance of digital certificates in secure communication.

---

# NMAP Experiments

22. Use Nmap to identify open, closed, and filtered ports on a host.

23. Use Nmap to detect services and software versions running on target hosts.

24. Use Nmap for operating system detection.

25. Save Nmap scan results into a file.

26. Explain the purpose and applications of the Nmap tool.

---

# Wireshark Experiments

27. Explain the purpose and applications of the Wireshark tool.

28. Capture TCP packets and save them into a packet capture file.

29. Find the sequence number of a TCP SYN packet and the corresponding SYN+ACK packet.

30. Find the time interval between two consecutive HTTP GET requests.

31. List and analyze all headers of a TCP packet.

32. Identify at least four protocols from captured network traffic.

---

# Frequency Analysis & Statistical Cryptanalysis

33. Generate the frequency distribution of characters in a ciphertext.

34. Use frequency analysis and Index of Coincidence to classify ciphertexts.

35. Perform ciphertext-only attacks on substitution ciphers using statistical analysis.

---

# IPTABLES Experiments

36. Configure IPTables rules to block incoming traffic from a specific IP address.

37. Configure IPTables to allow only SSH and HTTP services while blocking all other incoming traffic.

38. Use IPTables to restrict access to a specific port.

39. Save and restore IPTables firewall rules.

40. Monitor and list active IPTables firewall rules with packet statistics.
