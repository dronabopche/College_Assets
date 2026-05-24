# Configuring IPTables to Block Incoming Traffic from a Specific IP Address

## Aim

To configure IPTables rules to block incoming traffic from a specific IP address.

--- 

Check IPTables installation:

```bash id="l1h72e"
iptables --version
```

---

# Basic Syntax

```bash id="e4vjlwm"
sudo iptables -A INPUT -s <IP-ADDRESS> -j DROP
```

---

# Explanation

| Option     | Meaning                    |
| ---------- | -------------------------- |
| `-A INPUT` | Append rule to INPUT chain |
| `-s`       | Source IP address          |
| `-j DROP`  | Drop packets silently      |

---

# Example: Block a Specific IP Address

Suppose the IP address is:

```text id="9d7yrk"
192.168.1.100
```

## Command

```bash id="3a8f4r"
sudo iptables -A INPUT -s 192.168.1.100 -j DROP
```

---

# Verify IPTables Rules

## Command

```bash id="ng4f0j"
sudo iptables -L
```

---

# Sample Output

```text id="gqjlwm"
Chain INPUT (policy ACCEPT)
target     prot opt source            destination
DROP       all  --  192.168.1.100    anywhere
```

---

# Block Only TCP Traffic

## Command

```bash id="6u2m4k"
sudo iptables -A INPUT -p tcp -s 192.168.1.100 -j DROP
```

---

# Explanation

| Option   | Meaning                        |
| -------- | ------------------------------ |
| `-p tcp` | Apply rule only to TCP traffic |

---

# Block Traffic on a Specific Port

## Example: Block SSH Access from an IP

```bash id="3ez2yx"
sudo iptables -A INPUT -p tcp --dport 22 -s 192.168.1.100 -j DROP
```

---

# Remove the Rule

## Command

```bash id="8mjlwm"
sudo iptables -D INPUT -s 192.168.1.100 -j DROP
```

