# Detecting Services and Software Versions Using Nmap

## Aim

To detect services and software versions running on target hosts using Nmap.

---

# Requirements

Check installation:

```bash id="v83s5o"
nmap --version
```

---

# Basic Service Version Detection

## Command

```bash id="kjy8xy"
nmap -sV <target-IP>
```

Example:

```bash id="2h0bgw"
nmap -sV scanme.nmap.org
```

---

# Explanation

| Option            | Meaning                              |
| ----------------- | ------------------------------------ |
| `-sV`             | Detect service and software versions |
| `scanme.nmap.org` | Target host                          |

---

# Sample Output

```text id="jjcivv"
PORT    STATE SERVICE VERSION
22/tcp  open  ssh     OpenSSH 6.6.1
80/tcp  open  http    Apache httpd 2.4.7
53/tcp  open  domain  ISC BIND 9.9.5
```

---

# Understanding the Output

| Column  | Description      |
| ------- | ---------------- |
| PORT    | Port number      |
| STATE   | Port status      |
| SERVICE | Running service  |
| VERSION | Software version |

---

# Scan Specific Ports

## Command

```bash id="g0hks1"
nmap -sV -p 22,80,443 scanme.nmap.org
```

### Explanation

| Option      | Meaning             |
| ----------- | ------------------- |
| `-p`        | Scan selected ports |
| `22,80,443` | Specific ports      |

---

# Aggressive Service Detection

## Command

```bash id="8x77d5"
nmap -A scanme.nmap.org
```

---

# Features of `-A`

| Feature           | Description              |
| ----------------- | ------------------------ |
| OS Detection      | Detect operating system  |
| Version Detection | Detect software versions |
| NSE Scripts       | Run Nmap scripts         |
| Traceroute        | Show network path        |

---

# Detect Operating System and Services

## Command

```bash id="2z6i2j"
sudo nmap -O -sV scanme.nmap.org
```

---

# Sample Output

```text id="kh4lm6"
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 8.2p1 Ubuntu
80/tcp open  http    Apache httpd 2.4.41

OS details: Linux 5.x
```

---

# Service Detection Intensity

## Command

```bash id="4md1wf"
nmap -sV --version-intensity 5 scanme.nmap.org
```

### Explanation

| Option                | Meaning                  |
| --------------------- | ------------------------ |
| `--version-intensity` | Level of detection (0–9) |
| `5`                   | Medium intensity         |

