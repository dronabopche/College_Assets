# Configuring IPTables to Allow Only SSH and HTTP Services

## Aim

To configure IPTables to allow only SSH and HTTP incoming traffic while blocking all other incoming traffic.

---

# Introduction

iptables is a Linux firewall management tool used to:

* Control network traffic
* Allow or deny services
* Improve system security

In this configuration:

* SSH (Port 22) → Allowed
* HTTP (Port 80) → Allowed
* All other incoming traffic → Blocked

---

# Requirements

* Linux system
* Root or sudo privileges
* IPTables installed

Check installation:

```bash id="jlwmr5"
iptables --version
```

---

# Step 1: Clear Existing Rules

## Command

```bash id="tb67wf"
sudo iptables -F
```

### Explanation

| Option | Meaning                  |
| ------ | ------------------------ |
| `-F`   | Flush all existing rules |

---

# Step 2: Set Default Policies

## Block All Incoming Traffic

```bash id="cztguh"
sudo iptables -P INPUT DROP
```

---

## Allow Outgoing Traffic

```bash id="vx8z1t"
sudo iptables -P OUTPUT ACCEPT
```

---

## Allow Forwarded Traffic (Optional)

```bash id="50tepi"
sudo iptables -P FORWARD DROP
```

---

# Step 3: Allow Loopback Interface

## Command

```bash id="9jlwm5"
sudo iptables -A INPUT -i lo -j ACCEPT
```

### Explanation

| Option  | Meaning            |
| ------- | ------------------ |
| `-i lo` | Loopback interface |

---

# Step 4: Allow Established Connections

## Command

```bash id="21h8m4"
sudo iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
```

---

# Step 5: Allow SSH Service

## Command

```bash id="cud2dj"
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
```

---

# Step 6: Allow HTTP Service

## Command

```bash id="bh9jlwm"
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```

---

# Step 7: Verify Rules

## Command

```bash id="w7qv2m"
sudo iptables -L -v
```

---

# Sample Output

```text id="y4o2lb"
Chain INPUT (policy DROP)

ACCEPT tcp -- anywhere anywhere tcp dpt:ssh
ACCEPT tcp -- anywhere anywhere tcp dpt:http
```

---

# Rule Summary

| Service           | Port | Action |
| ----------------- | ---- | ------ |
| SSH               | 22   | ACCEPT |
| HTTP              | 80   | ACCEPT |
| All Other Traffic | Any  | DROP   |

---

# Save IPTables Rules

## Ubuntu/Debian

```bash id="w9jlwm"
sudo netfilter-persistent save
```

---

## CentOS/RHEL

```bash id="i2cfzy"
sudo service iptables save
```

---

# Testing the Configuration

## Test SSH

```bash id="pwcb0n"
ssh user@server-ip
```

---

## Test HTTP

Open browser:

```text id="l6o2on"
http://server-ip
```

---

# Result

IPTables was successfully configured to:

* Allow SSH traffic
* Allow HTTP traffic
* Block all other incoming traffic

---

# Conclusion

* IPTables rules were configured successfully.
* Only SSH and HTTP services were accessible.
* All other incoming traffic was blocked for improved security.
* Firewall filtering helps protect systems from unauthorized access.
