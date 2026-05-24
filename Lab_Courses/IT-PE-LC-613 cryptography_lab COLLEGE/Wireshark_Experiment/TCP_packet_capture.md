 # Capturing TCP Packets and Saving Them into a Packet Capture File

## Aim

To capture TCP packets and save them into a packet capture (`.pcap`) file.

---

# Introduction

Wireshark and tcpdump are commonly used tools for network packet capturing.

TCP packet capture helps in:

* Network troubleshooting
* Protocol analysis
* Security monitoring
* Traffic analysis

Captured packets are usually stored in:

* `.pcap`
* `.pcapng`

formats.

---

# Method 1: Using tcpdump

# Requirements

* tcpdump installed
* Root/administrator privileges

Check installation:

```bash id="4p3sfu"
tcpdump --version
```

---

# Step 1: Identify Network Interface

## Command

```bash id="7m07yl"
ip addr
```

or

```bash id="zqdfd5"
ifconfig
```

Common interfaces:

* `eth0`
* `wlan0`
* `enp0s3`

---

# Step 2: Capture TCP Packets

## Command

```bash id="cjlwm1"
sudo tcpdump -i eth0 tcp -w capture.pcap
```

---

## Explanation

| Option            | Meaning                  |
| ----------------- | ------------------------ |
| `sudo`            | Administrator privileges |
| `tcpdump`         | Packet capture tool      |
| `-i eth0`         | Network interface        |
| `tcp`             | Capture only TCP packets |
| `-w capture.pcap` | Save packets to file     |

---

# Step 3: Stop Capture

Press:

```text id="5ls43d"
CTRL + C
```

---

# Step 4: View Capture File Information

## Command

```bash id="rg0ytr"
tcpdump -r capture.pcap
```

---

# Sample Output

```text id="0pjlwm"
12:10:01 IP 192.168.1.5.443 > 192.168.1.10.51514: TCP
12:10:03 IP 192.168.1.10.51514 > 192.168.1.5.443: TCP
```

---

# Method 2: Using Wireshark

# Step 1: Start Wireshark

Open:

Wireshark

---

# Step 2: Select Network Interface

Choose:

* Ethernet
* Wi-Fi interface

---

# Step 3: Apply TCP Filter

In filter bar:

```text id="2f1ojl"
tcp
```

---

# Step 4: Start Packet Capture

Click:

* **Start Capture** button

---

# Step 5: Generate Network Traffic

Example:

* Open websites
* Ping systems
* Download files

---

# Step 6: Stop Capture

Click:

* **Stop Capture** button

---

# Step 7: Save Capture File

Go to:

```text id="e7nwzj"
File → Save As
```

Save as:

* `capture.pcap`
* `capture.pcapng`

