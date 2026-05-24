# Configuring IPTables to Allow Only SSH and HTTP

## Aim
To configure IPTables to allow only SSH and HTTP incoming traffic while blocking all other incoming traffic.

Allow only:

* SSH → Port 22
* HTTP → Port 80
* Block all other incoming traffic.

---

# Step 1: Clear Old Rules

```bash
sudo iptables -F
```

---

# Step 2: Block All Incoming Traffic

```bash
sudo iptables -P INPUT DROP
```

Allow outgoing traffic:

```bash
sudo iptables -P OUTPUT ACCEPT
```

---

# Step 3: Allow Localhost

```bash
sudo iptables -A INPUT -i lo -j ACCEPT
```

---

# Step 4: Allow Existing Connections

```bash
sudo iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
```

---

# Step 5: Allow SSH

```bash
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
```

---

# Step 6: Allow HTTP

```bash
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```

---

# Step 7: Check Rules

```bash
sudo iptables -L
```

---

# Save Rules

## Ubuntu/Debian

```bash
sudo netfilter-persistent save
```

## CentOS/RHEL

```bash
sudo service iptables save
```

---

# Result

* SSH allowed
* HTTP allowed
* All other incoming traffic blocked
