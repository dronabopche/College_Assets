# Saving and Restoring IPTables Firewall Rules

## Aim

To save and restore IPTables firewall rules in a Linux system.

---

# Introduction

iptables rules are stored in memory and are lost after reboot unless saved permanently.

Saving and restoring rules helps:

* Maintain firewall configuration
* Restore security settings after reboot
* Backup firewall rules

Linux provides:

* `iptables-save`
* `iptables-restore`

utilities for this purpose.

---

# Requirements

Check installation:

```bash id="jlwm9f"
iptables --version
```

---

# Step 1: View Current IPTables Rules

## Command

```bash id="e1x8q5"
sudo iptables -L -v
```

---

# Step 2: Save IPTables Rules

## Command

```bash id="96fjlwm"
sudo iptables-save > firewall_rules.backup
```

---

# Explanation

| Command                 | Purpose                     |
| ----------------------- | --------------------------- |
| `iptables-save`         | Save current firewall rules |
| `>`                     | Redirect output to file     |
| `firewall_rules.backup` | Backup file                 |

---

# Verify Saved File

## Command

```bash id="t5ddo4"
cat firewall_rules.backup
```

---

# Sample Saved Output

```text id="p4o5x8"
*filter
:INPUT DROP [0:0]
:FORWARD DROP [0:0]
:OUTPUT ACCEPT [0:0]
-A INPUT -p tcp --dport 22 -j ACCEPT
COMMIT
```

---

# Step 3: Flush Existing Rules (Optional)

## Command

```bash id="9jlwmr"
sudo iptables -F
```

---

# Step 4: Restore IPTables Rules

## Command

```bash id="6zk25s"
sudo iptables-restore < firewall_rules.backup
```

---

# Explanation

| Command            | Purpose                        |
| ------------------ | ------------------------------ |
| `iptables-restore` | Restore rules from backup file |
| `<`                | Read input from file           |

---

# Step 5: Verify Restored Rules

## Command

```bash id="e9sghm"
sudo iptables -L -v
```

---

# Save Rules Permanently

# Ubuntu/Debian

Install persistent package:

```bash id="l9jlwm"
sudo apt install iptables-persistent
```

Save rules:

```bash id="9l3nd2"
sudo netfilter-persistent save
```

