# Using Nmap to Identify Open, Closed, and Filtered Ports

## Aim

To identify open, closed, and filtered ports on a host using Nmap.

---

# Introduction

Nmap (Network Mapper) is a network scanning tool used for:

Port states:

* **Open** → Service is running and accepting connections
* **Closed** → Port is accessible but no service is running
* **Filtered** → Firewall or filtering blocks access

---

# Requirements

Check installation:

```bash id="8u9pln"
nmap --version
```

---

# Basic Syntax

```bash id="mdyq8l"
nmap <target-IP>
```

Example:

```bash id="n83l0u"
nmap 192.168.1.1
```

---

# Step 1: Scan a Host

## Command

```bash id="mq2lf9"
nmap scanme.nmap.org
```

---

# Sample Output

```text id="r1zj0n"
PORT     STATE    SERVICE
22/tcp   open     ssh
80/tcp   open     http
25/tcp   closed   smtp
139/tcp  filtered netbios-ssn
```

---

# Understanding Port States

| State    | Meaning                   |
| -------- | ------------------------- |
| Open     | Port accepts connections  |
| Closed   | Port reachable but unused |
| Filtered | Firewall blocks packets   |

---

# Step 2: Scan Specific Ports

## Command

```bash id="71pc2t"
nmap -p 20-100 scanme.nmap.org
```

### Explanation

| Option   | Meaning              |
| -------- | -------------------- |
| `-p`     | Specify port range   |
| `20-100` | Scan ports 20 to 100 |

---

# Step 3: Detect Service Versions

## Command

```bash id="ckz5aj"
nmap -sV scanme.nmap.org
```

---

# Sample Output

```text id="n4rlra"
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 8.0
80/tcp open  http    Apache httpd
```

---

# Step 4: SYN Scan (Stealth Scan)

## Command

```bash id="qhfjlwm"
sudo nmap -sS scanme.nmap.org
```

### Explanation

| Option | Meaning              |
| ------ | -------------------- |
| `-sS`  | TCP SYN stealth scan |

---

# Step 5: Scan All Ports

## Command

```bash id="o9md0r"
nmap -p- scanme.nmap.org
```

### Explanation

| Option | Meaning              |
| ------ | -------------------- |
| `-p-`  | Scan all 65535 ports |

---

# Step 6: Aggressive Scan

## Command

```bash id="ebzzyf"
nmap -A scanme.nmap.org
```

