# Saving Nmap Scan Results into a File

## Aim

To save Nmap scan results into a file for future analysis and reporting.

---

# Introduction

Nmap allows users to save scan results in different formats such as:

* Normal text
* XML
* Grepable format
* All formats together

Saving results helps in:

* Documentation
* Security auditing
* Report generation
* Future analysis

---

# Requirements

* Nmap installed
* Target host or IP address

Check installation:

```bash id="x53jlwm"
nmap --version
```

---

# 1. Save Output in Normal Format

## Command

```bash id="3kz2xu"
nmap scanme.nmap.org -oN result.txt
```

---

## Explanation

| Option       | Meaning                           |
| ------------ | --------------------------------- |
| `-oN`        | Save output in normal text format |
| `result.txt` | Output filename                   |

---

# View Saved File

```bash id="rlv6q3"
cat result.txt
```

---

# 2. Save Output in XML Format

## Command

```bash id="mgt2oe"
nmap scanme.nmap.org -oX result.xml
```

---

## Explanation

| Option | Meaning                   |
| ------ | ------------------------- |
| `-oX`  | Save output in XML format |

XML files are useful for:

* Automation
* Parsing
* Security tools integration

---

# 3. Save Output in Grepable Format

## Command

```bash id="bb2ed6"
nmap scanme.nmap.org -oG result.gnmap
```

---

## Explanation

| Option | Meaning                 |
| ------ | ----------------------- |
| `-oG`  | Save in grepable format |

Useful for:

* Filtering
* Searching
* Scripting

---

# 4. Save Output in All Formats

## Command

```bash id="wlol8h"
nmap scanme.nmap.org -oA fullscan
```

---

## Explanation

| Option | Meaning             |
| ------ | ------------------- |
| `-oA`  | Save in all formats |

Generated files:

* `fullscan.nmap`
* `fullscan.xml`
* `fullscan.gnmap`

---

# Example Scan with Service Detection

## Command

```bash id="c9lgvx"
nmap -sV scanme.nmap.org -oN services.txt
```

---

# Sample Saved Output

```text id="plqv0u"
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 8.2
80/tcp open  http    Apache httpd 2.4
```

---

# Observation Table

| Output Type | Option | File Extension |
| ----------- | ------ | -------------- |
| Normal      | `-oN`  | `.txt`         |
| XML         | `-oX`  | `.xml`         |
| Grepable    | `-oG`  | `.gnmap`       |
| All Formats | `-oA`  | Multiple       |

---

# Result

Nmap scan results were successfully saved into files using different output formats.

---

# Conclusion

* Nmap supports multiple output formats for saving scan results.
* Saved outputs help in documentation and analysis.
* XML and grepable formats are useful for automation and scripting.
* Saving results improves efficiency in network security assessment.
