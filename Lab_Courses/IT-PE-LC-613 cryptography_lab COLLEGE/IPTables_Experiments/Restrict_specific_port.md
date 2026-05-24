# Using IPTables to Restrict Access to a Specific Port

## Aim

To configure IPTables to restrict access to a specific network port.

---

# Introduction

iptables is a Linux firewall tool used to:

* Allow or block network traffic
* Protect services from unauthorized access
* Control access to ports

Restricting access to a port improves system security by limiting who can use a service.

---

# Requirements

* Linux system
* Root or sudo privileges
* IPTables installed

Check installation:

```bash id="tjlwm8"
iptables --version
```

---

# Basic Syntax

```bash id="uh9ehy"
sudo iptables -A INPUT -p tcp --dport <PORT> -j DROP
```

---

# Explanation

| Option     | Meaning                 |
| ---------- | ----------------------- |
| `-A INPUT` | Add rule to INPUT chain |
| `-p tcp`   | Apply to TCP traffic    |
| `--dport`  | Destination port        |
| `-j DROP`  | Drop packets            |

---

# Example 1: Restrict Access to Port 23 (Telnet)

## Command

```bash id="zbcjlwm"
sudo iptables -A INPUT -p tcp --dport 23 -j DROP
```

---

# Example 2: Restrict Access to Port 80 (HTTP)

## Command

```bash id="drx42l"
sudo iptables -A INPUT -p tcp --dport 80 -j DROP
```

---

# Example 3: Allow Only One IP to Access SSH Port 22

Suppose trusted IP:

```text id="rtr5u2"
192.168.1.10
```

---

## Allow Trusted IP

```bash id="pqqj5j"
sudo iptables -A INPUT -p tcp -s 192.168.1.10 --dport 22 -j ACCEPT
```

---

## Block All Other Access

```bash id="jlwmm7"
sudo iptables -A INPUT -p tcp --dport 22 -j DROP
```

---

# Verify IPTables Rules

## Command

```bash id="m1xy8g"
sudo iptables -L -v
```

---

# Sample Output

```text id="jlwmf8"
Chain INPUT

DROP tcp -- anywhere anywhere tcp dpt:23
DROP tcp -- anywhere anywhere tcp dpt:80
```

---

# Remove a Rule

## Command

```bash id="p0krbm"
sudo iptables -D INPUT -p tcp --dport 80 -j DROP
```

---

# Save IPTables Rules

## Ubuntu/Debian

```bash id="yjlwm2"
sudo netfilter-persistent save
```

---

## CentOS/RHEL

```bash id="kk0i8f"
sudo service iptables save
```

---

# Observation Table

| Port | Protocol | Action     |
| ---- | -------- | ---------- |
| 23   | TCP      | DROP       |
| 80   | TCP      | DROP       |
| 22   | TCP      | Restricted |

---

# Result

Access to the specified port was successfully restricted using IPTables.

---

# Conclusion

* IPTables successfully blocked access to selected ports.
* Specific services were restricted for security purposes.
* Trusted systems can be allowed while blocking others.
* IPTables is an effective firewall management utility for Linux systems.
