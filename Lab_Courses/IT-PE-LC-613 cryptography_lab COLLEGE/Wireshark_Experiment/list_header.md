# Listing and Analyzing TCP Packet Headers

## Aim

To list and analyze all headers of a TCP packet using packet analysis tools.

---

# Introduction

TCP (Transmission Control Protocol) is a reliable transport layer protocol used for:

* Web browsing
* Email
* File transfer
* Secure communication

A TCP packet contains:

1. IP Header
2. TCP Header
3. Data/Payload

TCP headers provide information required for:

* Reliable delivery
* Error checking
* Flow control
* Connection management

Tools used:

* Wireshark
* tcpdump

---

# Structure of a TCP Packet

```text id="v0z61r"
------------------------------------------------
| IP Header | TCP Header | Data/Payload |
------------------------------------------------
```

---

# TCP Header Format

```text id="pjjdln"
--------------------------------------------------------
| Source Port        | Destination Port               |
--------------------------------------------------------
| Sequence Number                                    |
--------------------------------------------------------
| Acknowledgment Number                              |
--------------------------------------------------------
| Data Offset | Reserved | Flags | Window Size       |
--------------------------------------------------------
| Checksum            | Urgent Pointer                |
--------------------------------------------------------
| Options (optional)                                  |
--------------------------------------------------------
| Data/Payload                                         |
--------------------------------------------------------
```

---

# Capturing a TCP Packet

## Using Wireshark

1. Open:

Wireshark

2. Start packet capture.
3. Apply filter:

```text id="rqg2ix"
tcp
```

4. Select a TCP packet.

---

# TCP Header Fields Analysis

| Header Field          | Description                       |
| --------------------- | --------------------------------- |
| Source Port           | Sender application port number    |
| Destination Port      | Receiver application port number  |
| Sequence Number       | Position of packet data in stream |
| Acknowledgment Number | Next expected byte                |
| Data Offset           | Size of TCP header                |
| Reserved              | Reserved bits for future use      |
| Flags                 | Control bits                      |
| Window Size           | Receiver buffer size              |
| Checksum              | Error detection                   |
| Urgent Pointer        | Indicates urgent data             |
| Options               | Additional TCP settings           |

---

# Example TCP Packet

```text id="h2g2iy"
Source Port: 51514
Destination Port: 80
Sequence Number: 1001
Acknowledgment Number: 5001
Header Length: 20 bytes
Flags: SYN, ACK
Window Size: 64240
Checksum: 0x1a2b
```

---

# TCP Flags Analysis

| Flag | Meaning                   |
| ---- | ------------------------- |
| SYN  | Start connection          |
| ACK  | Acknowledgment            |
| FIN  | End connection            |
| RST  | Reset connection          |
| PSH  | Push data immediately     |
| URG  | Urgent data               |
| ECE  | ECN Echo                  |
| CWR  | Congestion Window Reduced |

---

# Example SYN Packet

```text id="4jlwmg"
Flags: SYN
Sequence Number: 1000
Acknowledgment Number: 0
```

---

# Example SYN+ACK Packet

```text id="9u9vnn"
Flags: SYN, ACK
Sequence Number: 5000
Acknowledgment Number: 1001
```

---

# Observation Table

| Field            | Example Value |
| ---------------- | ------------- |
| Source Port      | 51514         |
| Destination Port | 80            |
| Sequence Number  | 1001          |
| ACK Number       | 5001          |
| Flags            | SYN, ACK      |
| Window Size      | 64240         |
| Checksum         | 0x1a2b        |

---

# Result

All TCP packet header fields were successfully identified and analyzed.

---

# Conclusion

* TCP packet headers provide important communication details.
* Each header field performs a specific function in reliable data transfer.
* Packet analysis tools help inspect TCP communication effectively.
* Understanding TCP headers is essential for networking and cybersecurity analysis.
