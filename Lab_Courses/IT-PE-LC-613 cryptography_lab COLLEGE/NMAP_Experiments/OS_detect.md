# Operating System Detection Using Nmap

## Aim

To detect the operating system of a target host using Nmap.

---

# Introduction

Nmap can identify the operating system running on a target host using TCP/IP stack fingerprinting.

OS detection helps in:

* Network administration
* Security auditing
* Vulnerability assessment
* Penetration testing

Nmap compares network responses with its OS fingerprint database to identify the target operating system.

---

# Requirements

* Nmap installed
* Target host or IP address
* Root/administrator privileges

Check installation:

```bash id="3avj60"
nmap --version
```

---

# Basic OS Detection

## Command

```bash id="8n3t3n"
sudo nmap -O <target-IP>
```

Example:

```bash id="l8je0y"
sudo nmap -O scanme.nmap.org
```

---

# Explanation

| Option | Meaning                        |
| ------ | ------------------------------ |
| `-O`   | Enable OS detection            |
| `sudo` | Required for accurate scanning |

---

# Sample Output

```text id="8dd5di"
PORT    STATE SERVICE
22/tcp  open  ssh
80/tcp  open  http

Device type: general purpose
Running: Linux 5.X
OS details: Linux 5.4 - 5.10
```

---

# Understanding the Output

| Field       | Description               |
| ----------- | ------------------------- |
| Device type | Type of system            |
| Running     | Detected operating system |
| OS details  | Specific OS version       |

---

# Aggressive OS Detection

## Command

```bash id="gqk6f9"
sudo nmap -A scanme.nmap.org
```

---

# Features of `-A`

| Feature           | Description             |
| ----------------- | ----------------------- |
| OS Detection      | Detect operating system |
| Version Detection | Detect services         |
| NSE Scripts       | Run scripts             |
| Traceroute        | Show network path       |

---

# Verbose OS Detection

## Command

```bash id="c7i4kh"
sudo nmap -O -v scanme.nmap.org
```

### Explanation

| Option | Meaning        |
| ------ | -------------- |
| `-v`   | Verbose output |

---

# Detect OS and Service Versions Together

## Command

```bash id="m1u8oa"
sudo nmap -O -sV scanme.nmap.org
```

---

# Sample Output

```text id="5p5lwb"
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 8.2
80/tcp open  http    Apache httpd 2.4

OS details: Linux Ubuntu 20.04
```

---

# Observation Table

| Host            | Detected OS | Accuracy |
| --------------- | ----------- | -------- |
| scanme.nmap.org | Linux 5.x   | High     |
| 192.168.1.1     | Windows 10  | Medium   |

---

# Result

The operating system of the target host was successfully detected using Nmap.

---

# Conclusion

* Nmap successfully identified the operating system of the target host.
* OS fingerprinting provides useful information for network analysis and security testing.
* Accurate OS detection helps administrators and security professionals assess systems effectively.
