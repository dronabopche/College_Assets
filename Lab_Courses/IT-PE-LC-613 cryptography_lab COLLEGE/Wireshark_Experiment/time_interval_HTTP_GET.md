# Finding the Time Interval Between Two Consecutive HTTP GET Requests

## Aim

To find the time interval between two consecutive HTTP GET requests using packet analysis tools.

---

# Introduction

HTTP GET requests are used by clients (such as web browsers) to request web pages or resources from a server.

By analyzing captured packets, we can determine:

* Timestamp of each request
* Time difference between requests
* Client browsing behavior
* Network performance

Tools commonly used:

* Wireshark
* tcpdump

---

# Requirements

* Wireshark or tcpdump installed
* Packet capture (`.pcap`) file or live traffic

---

# Method 1: Using Wireshark

# Step 1: Open Wireshark

Launch:

Wireshark

---

# Step 2: Open Capture File

Go to:

```text id="u2d2rm"
File → Open
```

Select the `.pcap` file.

---

# Step 3: Apply HTTP GET Filter

In the filter bar, type:

```text id="eb2sn0"
http.request.method == "GET"
```

This displays only HTTP GET requests.

---

# Step 4: Identify Two Consecutive GET Requests

Example:

| Packet No. | Time      | Request         |
| ---------- | --------- | --------------- |
| 15         | 10.245678 | GET /index.html |
| 18         | 12.987654 | GET /image.png  |

---

# Step 5: Calculate Time Interval

Formula:

```text id="n7upkl"
Time Interval = Second Request Time - First Request Time
```

Calculation:

```text id="zjlwm5"
12.987654 - 10.245678 = 2.741976 seconds
```

---

# Result

Time interval between the two HTTP GET requests:

```text id="bqzhmu"
2.741976 seconds
```

---

# Method 2: Using tcpdump

## Read HTTP Packets

```bash id="95gpg6"
tcpdump -nn -r capture.pcap
```

---

## Filter HTTP Traffic

```bash id="5t4pgo"
tcpdump -nn -A -r capture.pcap port 80
```

