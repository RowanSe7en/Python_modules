# 🗄️ Data Archivist — Module 04

> **Digital Preservation in the Cyber Archives**  
> *42 Network — Python Cursus*

---

## 📖 About

**Data Archivist** is the fifth module of the 42 Python cursus, set in the year 2087 where humanity's most valuable resource is data. This module focuses on **file I/O, stream management, context managers, and combined error handling** — the fundamental skills that turn a programmer into a true data engineer.

Building on exception handling (Module 02) and collections (Module 03), you now learn to interact with the file system itself: opening vaults, reading ancient fragments, writing new archives, managing the three sacred data streams (`stdin`, `stdout`, `stderr`), and responding to crises when things go wrong.

> 🗺️ You are a Data Archivist trainee in the Digital Preservation Division. Five missions stand between you and full certification.

---

## 🗂️ Project Structure

```
module04/
├── attachments/
│   └── data-generator-tools.tar.gz   ← extract this first!
├── ex0/
│   └── ft_ancient_text.py
├── ex1/
│   └── ft_archive_creation.py
├── ex2/
│   └── ft_stream_management.py
├── ex3/
│   └── ft_vault_security.py
└── ex4/
    └── ft_crisis_response.py
```

---

## 📋 Exercises Overview

| Mission | Exercise | File | Core Concept |
|---------|----------|------|--------------|
| **Mission 0** | Ancient Text Recovery | `ft_ancient_text.py` | Reading files with `open()` / `read()` |
| **Mission 1** | Archive Creation | `ft_archive_creation.py` | Writing files with `open('w')` / `write()` |
| **Mission 2** | Stream Management | `ft_stream_management.py` | `stdin`, `stdout`, `stderr` — the 3 streams |
| **Mission 3** | Vault Security | `ft_vault_security.py` | Context managers — the `with` statement |
| **Mission 4** | Crisis Response | `ft_crisis_response.py` | `try/except` + `with` — full error handling |

---

## 🔧 Technical Requirements

- **Language:** Python 3.10+
- **Authorized imports:** `sys` only
- **Authorized built-ins:** `open()`, `read()`, `write()`, `close()`, `print()`, `input()`
- **Mandatory pattern:** Always use the `with` statement when opening files (Ex03 onward)
- **Error handling:** All operations must fail gracefully — no unhandled crashes
- **Style:** Clean, simple, readable code — evaluated on understanding, not complexity

---

## 🧪 Training Resources

A tools archive is provided in the `attachments/` directory. Extract it before starting:

```bash
tar -xzf data-generator-tools.tar.gz
```

Then generate the test data files required by the exercises:

```bash
python3 data_generator.py
```

| Generated file | Required by |
|----------------|-------------|
| `ancient_fragment.txt` | Exercise 0 |
| `standard_archive.txt` | Exercise 4 |
| Other test files | Exercise 4 (crisis scenarios) |

> ⚠️ The Archives' security protocols require specific file names and content formats. Generate the data before running any exercise — your program reads from exact filenames.

Additional references in `data_samples/` and `sample_data.json` are for reference only — do not submit them.

---

## 📝 Exercise Details

### Mission 0 — Ancient Text Recovery

Learn the most fundamental file operation: **reading** an existing file.

Your program opens `ancient_fragment.txt`, reads its contents, and displays the recovery log. If the file doesn't exist (because the data generator hasn't been run), it must print an informative error instead of crashing.

**Key behavior:**
- File found → display system header, vault access status, recovered data, completion message
- File not found → print `ERROR: Storage vault not found. Run data generator first.`

```
$> python3 ft_ancient_text.py
=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===
Accessing Storage Vault: ancient_fragment.txt
Connection established...

RECOVERED DATA:
[FRAGMENT 001] Digital preservation protocols established 2087
[FRAGMENT 002] Knowledge must survive the entropy wars
[FRAGMENT 003] Every byte saved is a victory against oblivion

Data recovery complete. Storage unit disconnected.
```

> 💡 Think about what happens if the file handle is never closed. Why is the disconnect protocol critical?

Authorized: `open()`, `read()`, `close()`, `print()`

---

### Mission 1 — Archive Creation

Learn to **write** a new file. Unlike reading, writing is permanent — once you seal the vault, the data becomes part of the eternal Archives.

Create `new_discovery.txt` and inscribe exactly three entries: a quantum algorithm discovery, performance metrics (347% efficiency gain), and your archivist identification.

**Key behavior:**
- Open file in `'w'` mode (creates new or overwrites existing)
- Write numbered entries in the specified format
- Confirm creation on screen

```
$> python3 ft_archive_creation.py
=== CYBER ARCHIVES - PRESERVATION SYSTEM ===
Initializing new storage unit: new_discovery.txt
Storage unit created successfully...

Inscribing preservation data...
[ENTRY 001] New quantum algorithm discovered
[ENTRY 002] Efficiency increased by 347%
[ENTRY 003] Archived by Data Archivist trainee

Data inscription complete. Storage unit sealed.
Archive 'new_discovery.txt' ready for long-term preservation.
```

> ⚠️ **Critical distinction to know for evaluation:** `'r'` (extraction mode) reads an existing file. `'w'` (preservation mode) creates a new file or **completely replaces** an existing one. Accidentally using `'w'` on a historical archive destroys it forever.

Authorized: `open()`, `write()`, `close()`, `print()`

---

### Mission 2 — Stream Management

Master the **three sacred data channels** that all Unix/Linux programs use:

| Stream | Object | Purpose |
|--------|--------|---------|
| `stdin` | `sys.stdin` / `input()` | Receive messages from users |
| `stdout` | `sys.stdout` / `print()` | Standard broadcast output |
| `stderr` | `sys.stderr` | Emergency alerts and errors |

Your program collects an archivist ID and a status report via `input()`, then demonstrates proper stream separation: regular messages go to `stdout`, diagnostic alerts go to `stderr`.

```
$> python3 ft_stream_management.py
=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===
Input Stream active. Enter archivist ID: ARCH_7742
Input Stream active. Enter status report: All systems nominal
[STANDARD] Archive status from ARCH_7742: All systems nominal
[ALERT] System diagnostic: Communication channels verified
[STANDARD] Data transmission complete
Three-channel communication test successful.
```

> ⚠️ Never mix streams! `stderr` exists so that error messages can be redirected or suppressed independently from normal output — mixing them defeats the entire purpose of stream separation.

Authorized: `sys.stdin`, `sys.stdout`, `sys.stderr`, `input()`, `print()`, `import sys`

---

### Mission 3 — Vault Security

This is where you stop using `open()` + `close()` manually and adopt the **`with` statement** — the context manager protocol that guarantees automatic cleanup.

```python
# Without with — dangerous, close() might never be called
f = open("vault.txt", "r")
data = f.read()
f.close()

# With with — the vault ALWAYS seals, even on exceptions
with open("vault.txt", "r") as f:
    data = f.read()
```

Implement secure read **and** write operations using `with`, demonstrating automatic vault sealing in both cases.

```
$> python3 ft_vault_security.py
=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===
Initiating secure vault access...
Vault connection established with failsafe protocols

SECURE EXTRACTION:
[CLASSIFIED] Quantum encryption keys recovered
[CLASSIFIED] Archive integrity: 100%

SECURE PRESERVATION:
[CLASSIFIED] New security protocols archived
Vault automatically sealed upon completion

All vault operations completed with maximum security.
```

> 💡 The **RAII principle** (Resource Acquisition Is Initialization): resources are tied to scope — when scope exits (normally or via exception), resources are released automatically. The `with` statement is Python's implementation of this principle. Know this for your eval.

Authorized: `open()`, `read()`, `write()`, `with` statement, `print()`

---

### Mission 4 — Crisis Response *(Capstone)*

The ultimate test: combine everything — `with`, `try/except`, and multiple error types — into a **crisis management system** that handles real-world archive failures gracefully.

**Data preparation:** run the data generator first to create `standard_archive.txt` and the other test files:

```bash
python3 tools/data_generator.py
```

**Crisis categories to handle:**

| Scenario | File | Exception | Response |
|----------|------|-----------|----------|
| Missing archive | `lost_archive.txt` | `FileNotFoundError` | "Archive not found in storage matrix" |
| Security violation | `classified_vault.txt` | `PermissionError` | "Security protocols deny access" |
| Routine success | `standard_archive.txt` | *(none)* | Display recovered content |

```
$> python3 ft_crisis_response.py
=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===

CRISIS ALERT: Attempting access to 'lost_archive.txt'...
RESPONSE: Archive not found in storage matrix
STATUS: Crisis handled, system stable

CRISIS ALERT: Attempting access to 'classified_vault.txt'...
RESPONSE: Security protocols deny access
STATUS: Crisis handled, security maintained

ROUTINE ACCESS: Attempting access to 'standard_archive.txt'...
SUCCESS: Archive recovered - "Knowledge preserved for humanity"
STATUS: Normal operations resumed

All crisis scenarios handled successfully. Archives secure.
```

> ⚠️ **Output format matters here.** The subject explicitly states to follow the format precisely for consistency across the Archives network — each access attempt must display ALERT/RESPONSE/STATUS in that exact three-line structure.

Authorized: `open()`, `read()`, `write()`, `with` statement, `try/except`, `print()`

---

## 🧠 Concepts Introduced

| Concept | First seen | Python mechanism |
|---------|-----------|-----------------|
| Reading files | Ex00 | `open('r')`, `read()`, `close()` |
| Writing files | Ex01 | `open('w')`, `write()`, `close()` |
| File modes | Ex01 | `'r'` vs `'w'` vs `'a'` |
| Standard streams | Ex02 | `sys.stdin`, `sys.stdout`, `sys.stderr` |
| Context managers | Ex03 | `with open(...) as f:` |
| RAII / auto-close | Ex03 | Automatic cleanup on scope exit |
| Combined error + file handling | Ex04 | `try/except` + `with` |
| Error type differentiation | Ex04 | `FileNotFoundError`, `PermissionError` |

---

## 🔗 File Mode Reference

| Mode | Name | Behavior |
|------|------|----------|
| `'r'` | Read (extraction) | Opens existing file for reading. Fails if file doesn't exist. |
| `'w'` | Write (preservation) | Creates new file or **truncates** existing one completely. |
| `'a'` | Append | Creates new file or appends to existing one without truncating. |
| `'r+'` | Read + Write | Opens existing file for both reading and writing. |

---

## 🔗 Stream Reference

| Stream | Default target | Use case |
|--------|---------------|----------|
| `sys.stdout` | Terminal | Normal program output |
| `sys.stderr` | Terminal (separate) | Errors, warnings, diagnostics |
| `sys.stdin` | Keyboard | Reading user input |

Streams can be redirected independently on the command line:
```bash
python3 script.py 2>/dev/null     # suppress stderr, keep stdout
python3 script.py 1>output.txt    # redirect stdout to file
python3 script.py 2>&1            # merge stderr into stdout
```

This is precisely why separating them in code matters — callers control each channel independently.

---

## 🚀 Running the Exercises

```bash
# Step 1: extract tools and generate test data
tar -xzf attachments/data-generator-tools.tar.gz
python3 data_generator.py

# Step 2: run each exercise
cd ex0/ && python3 ft_ancient_text.py
cd ex1/ && python3 ft_archive_creation.py
cd ex2/ && python3 ft_stream_management.py
cd ex3/ && python3 ft_vault_security.py
cd ex4/ && python3 ft_crisis_response.py
```

---

## ⚠️ Important Rules

- **Always use `with`** when opening files in Ex03 and Ex04 — bare `open()`/`close()` without a context manager is unsafe and will be flagged during evaluation
- **Never import anything except `sys`** — no `os`, `pathlib`, `shutil`, or any third-party libraries
- Programs must **never crash** — all file errors must be caught and handled
- The output structure for Ex04 (ALERT/RESPONSE/STATUS per scenario) must match the expected format precisely
- You may customize flavor text in Ex00–Ex03 as long as the core information is preserved

---

## 🤖 AI Usage Policy

AI tools are **permitted** with the following rules:

- ✅ Use AI to explore file mode differences, understand `with` statement internals, and clarify stream behavior
- ✅ Only submit code you **fully understand** and can explain line by line
- ❌ During peer evaluation you'll be asked to explain `with` vs manual `open/close`, why streams are separated, and how `try/except` combines with file I/O — "I got it from AI" is not an answer
- ❌ Do not copy-paste solutions you cannot trace through manually

---

## 📦 Submission

Submit all files via your **Git repository**. Only files tracked in the repo will be evaluated.

Files to submit:
- `ex0/ft_ancient_text.py`
- `ex1/ft_archive_creation.py`
- `ex2/ft_stream_management.py`
- `ex3/ft_vault_security.py`
- `ex4/ft_crisis_response.py`

> Do **not** submit the data generator tools, generated `.txt` files, or the `attachments/` directory — only the five `.py` files listed above.

---

*"Every file is a piece of history worth preserving, and every operation is a responsibility to future generations."*
