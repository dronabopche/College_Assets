# Finding the Sequence Number of a TCP SYN Packet and SYN+ACK Packet

## Aim

To identify the sequence number of a TCP SYN packet and the corresponding SYN+ACK packet using packet analysis tools.

---

# Introduction

In a TCP three-way handshake:

1. **SYN** → Client requests connection
2. **SYN+ACK** → Server acknowledges request
3. **ACK** → Client confirms connection

TCP packets contain:

* Sequence Number
* Acknowledgment Number
* Flags

These values help establish reliable communication.

---

# Tools Required

* Wireshark or tcpdump
* Captured `.pcap` file or live network traffic

---

# Method 1: Using Wireshark

# Step 1: Open Wireshark

Launch:

Wireshark

---

# Step 2: Start Capture or Open PCAP File

* Start live capture
  OR
* Open an existing `.pcap` file

---

# Step 3: Apply TCP SYN Filter

In the filter bar, type:

```text id="9lbjlwm"
tcp.flags.syn == 1 && tcp.flags.ack == 0
```

This displays only SYN packets.

---

# Step 4: Identify SYN Packet

Example packet:

```text id="lxfuh8"
Source: 192.168.1.10
Destination: 192.168.1.5
Flags: SYN
Sequence Number: 1000
```

---

# Step 5: Find Corresponding SYN+ACK Packet

Apply filter:

```text id="yu97o7"
tcp.flags.syn == 1 && tcp.flags.ack == 1
```

---

# Example SYN+ACK Packet

```text id="d8e3lh"
Source: 192.168.1.5
Destination: 192.168.1.10
Flags: SYN, ACK
Sequence Number: 5000
Acknowledgment Number: 1001
```

---

# Explanation

| Packet  | Sequence Number | Acknowledgment Number |
| ------- | --------------- | --------------------- |
| SYN     | 1000            | —                     |
| SYN+ACK | 5000            | 1001                  |

The server acknowledges:

```text id="p94hgs"
Client Sequence Number + 1
```

---

# TCP Three-Way Handshake

```text id="4kegw0"
Client  → SYN      Seq = 1000
Server  → SYN+ACK  Seq = 5000 Ack = 1001
Client  → ACK      Ack = 5001
```

---

# Method 2: Using tcpdump

## Capture TCP Packets

```bash id="bnffm9"
sudo tcpdump -i eth0 tcp -w capture.pcap
```

---

## Read Capture File

```bash id="4lfqzb"
tcpdump -nn -r capture.pcap
```

---

# Observation Table

| Packet Type | Source | Destination | Seq No. | Ack No. |
| ----------- | ------ | ----------- | ------- | ------- |
| SYN         | Client | Server      | 1000    | —       |
| SYN+ACK     | Server | Client      | 5000    | 1001    |

---

# Result

The sequence number of the TCP SYN packet and the corresponding SYN+ACK packet were successfully identified.

---

# Conclusion

* TCP handshake packets were analyzed successfully.
* Sequence and acknowledgment numbers were identified correctly.
* SYN packets initiate communication, while SYN+ACK packets acknowledge the request.
* Packet analysis tools help understand TCP communication and troubleshooting.
