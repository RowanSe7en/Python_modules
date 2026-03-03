# 🎮 Data Quest — Module 03

> **Mastering Python Collections for Data Engineering**  
> *42 Network — Python Cursus*

---

## 📖 About

**Data Quest** is the fourth module of the 42 Python cursus, stepping into the **Pixel Dimension** — a game analytics context used to teach Python's most powerful data structures. Building on the foundations of syntax (Module 00), OOP (Module 01), and exception handling (Module 02), this module focuses entirely on collections and data processing patterns.

You'll build **PixelMetrics 3000** — a game analytics platform — piece by piece across 7 exercises, each introducing a new data structure or processing technique: lists, tuples, sets, dictionaries, generators, and comprehensions.

> 🎯 Think of it like a Pokémon journey — each exercise unlocks a new data superpower.

---

## 🗂️ Project Structure

```
module03/
├── ex0/
│   └── ft_command_quest.py
├── ex1/
│   └── ft_score_analytics.py
├── ex2/
│   └── ft_coordinate_system.py
├── ex3/
│   └── ft_achievement_tracker.py
├── ex4/
│   └── ft_inventory_system.py
├── ex5/
│   └── ft_data_stream.py
└── ex6/
    └── ft_analytics_dashboard.py
```

---

## 📋 Exercises Overview

| Level | Exercise | File | Data Structure / Concept |
|-------|----------|------|--------------------------|
| **Lv.0** | Command Quest | `ft_command_quest.py` | `sys.argv`, command-line arguments |
| **Lv.1** | Score Cruncher | `ft_score_analytics.py` | **Lists** — sequential data, statistics |
| **Lv.2** | Position Tracker | `ft_coordinate_system.py` | **Tuples** — immutable 3D coordinates |
| **Lv.3** | Achievement Hunter | `ft_achievement_tracker.py` | **Sets** — unique collections, set operations |
| **Lv.4** | Inventory Master | `ft_inventory_system.py` | **Dictionaries** — key-value lookups, nesting |
| **Lv.5** | Stream Wizard | `ft_data_stream.py` | **Generators** — memory-efficient streaming |
| **Lv.6** | Data Alchemist | `ft_analytics_dashboard.py` | **Comprehensions** — list, dict, set |

---

## 🔧 Technical Requirements

- **Language:** Python 3.10+
- **Linting:** All code must pass `flake8` standards
- **Imports:** Only `sys` is allowed — no file I/O, no `json`, no third-party libraries
- **Data source:** All data must be processed **in-memory** or via **command-line arguments** — no file reading/writing
- **Structure:** Each exercise in its own file, one exercise per directory
- **Crash policy:** Handle exceptions gracefully — programs must never crash
- Show both **basic operations** and **advanced techniques** for each data structure

---

## 🧪 Testing Tools

A testing archive `data_quest_tools.tar.gz` is provided alongside the project. Extract it with:

```bash
tar -xzf data_quest_tools.tar.gz
```

| Tool | Purpose |
|------|---------|
| `data_generator.py` | Generate command-line ready test data for all exercises |
| `exercise_0_help.py` | Explore `sys.argv` and command-line arguments |
| `exercise_1_helper.py` | Score analytics with realistic data patterns |
| `advanced_data_helper.py` | Complex data scenarios and performance testing |

```bash
# Generate test data for all exercises
python3 data_generator.py

# Generate argv-ready data for exercise 1 (10 scores)
python3 data_generator.py 1 --count 10 --format argv
```

> ⚠️ Testing tools are **not submitted or graded** — they are for your own validation only.

---

## 📝 Exercise Details

### Lv.0 — Command Quest

Learn how programs receive data from the outside world via `sys.argv`. Every exercise from Lv.1 onward uses this concept.

**Key behaviors:**
- No arguments → print a "No arguments provided!" message with program name and total count
- With arguments → list each argument with its index, total count

```
$> python3 ft_command_quest.py
=== Command Quest ===
No arguments provided!
Program name: ft_command_quest.py
Total arguments: 1

$> python3 ft_command_quest.py hello world 42
=== Command Quest ===
Program name: ft_command_quest.py
Arguments received: 3
Argument 1: hello
Argument 2: world
Argument 3: 42
Total arguments: 4
```

> 💡 `sys.argv[0]` is always the program name. User-provided arguments start at index 1.

Authorized: `import sys`, `sys.argv`, `len()`, `print()`

---

### Lv.1 — Score Cruncher

**Lists** — your ordered, expandable inventory for sequential data.

Accept player scores as command-line arguments, convert them, and compute analytics. Handle non-numeric input gracefully with `try/except`.

**Output stats:** scores list, total players, total score, average, high score, low score, score range.

```
$> python3 ft_score_analytics.py 1500 2300 1800 2100 1950
=== Player Score Analytics ===
Scores processed: [1500, 2300, 1800, 2100, 1950]
Total players: 5
Total score: 9650
Average score: 1930.0
High score: 2300
Low score: 1500
Score range: 800

$> python3 ft_score_analytics.py
=== Player Score Analytics ===
No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...
```

Authorized: `sys.argv`, `len()`, `sum()`, `max()`, `min()`, `int()`, `print()`, `try/except`

---

### Lv.2 — Position Tracker

**Tuples** — immutable, reliable containers. Perfect for coordinates that must never change accidentally.

Build a 3D coordinate system with parsing, distance calculation, and tuple unpacking.

**Distance formula (3D Euclidean):**
```
distance = math.sqrt((x2-x1)² + (y2-y1)² + (z2-z1)²)
```

**Key demonstrations:**
- Create a 3D position tuple: `(x, y, z)`
- Parse a coordinate string like `"3,4,0"` into a tuple
- Calculate distance from the origin
- Handle invalid coordinate strings (`"abc,def,ghi"`) with `ValueError`
- Demonstrate tuple unpacking: `x, y, z = position`

```
$> python3 ft_coordinate_system.py
=== Game Coordinate System ===
Position created: (10, 20, 5)
Distance between (0, 0, 0) and (10, 20, 5): 22.91
Parsing coordinates: "3,4,0"
Parsed position: (3, 4, 0)
Distance between (0, 0, 0) and (3, 4, 0): 5.0
Parsing invalid coordinates: "abc,def,ghi"
Error parsing coordinates: invalid literal for int() with base 10: 'abc'
Unpacking demonstration:
Player at x=3, y=4, z=0
Coordinates: X=3, Y=4, Z=0
```

Authorized: `import sys`, `sys.argv`, `import math`, `tuple()`, `int()`, `float()`, `print()`, `split()`, `try/except`, `math.sqrt()`

---

### Lv.3 — Achievement Hunter

**Sets** — unique collections with built-in deduplication and algebra-style operations.

Track player achievements across multiple players and perform analytics using set operations.

**Set operations to demonstrate:**

| Operation | Method | Meaning |
|-----------|--------|---------|
| All achievements | `union()` | Everything any player has |
| Shared by all | `intersection()` | What everyone has in common |
| Exclusive to one | `difference()` | What only one player has |
| Rare (1 player only) | Custom logic | Bragging rights |

```
$> python3 ft_achievement_tracker.py
=== Achievement Tracker System ===
Player alice achievements: {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
Player bob achievements: {'first_kill', 'level_10', 'boss_slayer', 'collector'}
Player charlie achievements: {'level_10', 'treasure_hunter', 'boss_slayer', 'speed_demon', 'perfectionist'}

=== Achievement Analytics ===
All unique achievements: {'boss_slayer', 'collector', 'first_kill', 'level_10', 'perfectionist', 'speed_demon', 'treasure_hunter'}
Total unique achievements: 7
Common to all players: {'level_10'}
Rare achievements (1 player): {'collector', 'perfectionist'}
Alice vs Bob common: {'first_kill', 'level_10'}
Alice unique: {'speed_demon', 'treasure_hunter'}
Bob unique: {'boss_slayer', 'collector'}
```

Authorized: `set()`, `len()`, `print()`, `union()`, `intersection()`, `difference()`

---

### Lv.4 — Inventory Master

**Dictionaries** — instant key-based lookups. The backbone of every game's data model.

Build a full player inventory system with nested dicts, transaction support, and analytics reporting.

**Data modeled:** item name → `{type, rarity, quantity, value}` — a nested dictionary structure.

**Features to implement:**
- Display a formatted inventory per player (item, type, rarity, quantity, unit value, total value)
- Calculate total inventory value and item count, broken down by category
- Simulate a transaction between two players (e.g. Alice gives Bob 2 potions)
- Analytics: most valuable player, most items, rarest items

```
$> python3 ft_inventory_system.py
=== Player Inventory System ===
=== Alice's Inventory ===
sword (weapon, rare): 1x @ 500 gold each = 500 gold
potion (consumable, common): 5x @ 50 gold each = 250 gold
shield (armor, uncommon): 1x @ 200 gold each = 200 gold
Inventory value: 950 gold
...
=== Inventory Analytics ===
Most valuable player: Alice (850 gold)
Most items: Alice (5 items)
Rarest items: sword, magic_ring
```

Authorized: `dict()`, `len()`, `print()`, `keys()`, `values()`, `items()`, `get()`, `update()`

---

### Lv.5 — Stream Wizard

**Generators** — Python's memory-saving superpower. Process infinite or massive data streams without loading everything into RAM.

Build a game event stream processor using `yield`. Show the contrast between storing all data (list) vs streaming it (generator).

**Key demonstrations:**
- A generator function using `yield` to emit game events one by one
- Process 1000+ events with constant memory usage
- Filter events during streaming (e.g. high-level players, treasure finds, level-ups)
- Collect statistics without storing all events
- Bonus: Fibonacci and prime number generators to illustrate the concept cleanly

```
$> python3 ft_data_stream.py
=== Game Data Stream Processor ===
Processing 1000 game events...
Event 1: Player alice (level 5) killed monster
Event 2: Player bob (level 12) found treasure
...
=== Stream Analytics ===
Total events processed: 1000
High-level players (10+): 342
Treasure events: 89
Level-up events: 156
Memory usage: Constant (streaming)

=== Generator Demonstration ===
Fibonacci sequence (first 10): 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
Prime numbers (first 5): 2, 3, 5, 7, 11
```

Authorized: `yield`, `next()`, `iter()`, `range()`, `len()`, `print()`, `for` loops

---

### Lv.6 — Data Alchemist *(Capstone)*

**Comprehensions** — Python's one-liner data transformation spells. Combine everything you've learned into a final analytics dashboard.

Demonstrate all three comprehension types clearly, using simple hardcoded sample data.

**Three comprehension types required:**

| Type | Syntax | Use case |
|------|--------|----------|
| List comprehension | `[expr for x in iterable if cond]` | Filter/transform sequences |
| Dict comprehension | `{k: v for k, v in iterable}` | Build mappings, group data |
| Set comprehension | `{expr for x in iterable}` | Deduplicate, find unique values |

```
$> python3 ft_analytics_dashboard.py
=== Game Analytics Dashboard ===
=== List Comprehension Examples ===
High scorers (>2000): ['alice', 'charlie', 'diana']
Scores doubled: [4600, 3600, 4300, 4100]
Active players: ['alice', 'bob', 'charlie']

=== Dict Comprehension Examples ===
Player scores: {'alice': 2300, 'bob': 1800, 'charlie': 2150}
Score categories: {'high': 3, 'medium': 2, 'low': 1}
Achievement counts: {'alice': 5, 'bob': 3, 'charlie': 7}

=== Set Comprehension Examples ===
Unique players: {'alice', 'bob', 'charlie', 'diana'}
Unique achievements: {'first_kill', 'level_10', 'boss_slayer'}
Active regions: {'north', 'east', 'central'}

=== Combined Analysis ===
Total players: 4
Total unique achievements: 12
Average score: 2062.5
Top performer: alice (2300 points, 5 achievements)
```

> ⚠️ **Note:** The example output shows possibilities — your exact output may differ. What matters is **demonstrating all three comprehension types clearly**. Keep the data simple and hardcoded. Do not overcomplicate.

Authorized: list/dict/set comprehensions, `len()`, `print()`, `sum()`, `max()`, `min()`, `sorted()`

---

## 🧠 Collection Quick Reference

| Collection | Syntax | Ordered | Mutable | Duplicates | Best for |
|------------|--------|---------|---------|------------|----------|
| `list` | `[a, b, c]` | ✅ | ✅ | ✅ | Sequential data, scores |
| `tuple` | `(a, b, c)` | ✅ | ❌ | ✅ | Fixed data, coordinates |
| `set` | `{a, b, c}` | ❌ | ✅ | ❌ | Unique values, set algebra |
| `dict` | `{k: v}` | ✅ (3.7+) | ✅ | Keys: ❌ | Lookups, mappings, records |
| `generator` | `yield` | ✅ (lazy) | ❌ | ✅ | Large/infinite data streams |

---

## 🧠 Concepts Introduced

| Concept | First seen |
|---------|-----------|
| `sys.argv` / command-line args | Lv.0 |
| `list` operations (`sum`, `max`, `min`) | Lv.1 |
| `tuple` immutability & unpacking | Lv.2 |
| 3D Euclidean distance (`math.sqrt`) | Lv.2 |
| `set` operations (`union`, `intersection`, `difference`) | Lv.3 |
| `dict` nesting, `.items()`, `.get()`, `.update()` | Lv.4 |
| `yield` / generator functions | Lv.5 |
| List / dict / set comprehensions | Lv.6 |

---

## 🚀 Running the Exercises

All exercises accept data via command-line arguments (except Lv.0, Lv.3–6 which use hardcoded sample data):

```bash
cd ex0/ && python3 ft_command_quest.py hello world 42
cd ex1/ && python3 ft_score_analytics.py 1500 2300 1800 2100 1950
cd ex2/ && python3 ft_coordinate_system.py
cd ex3/ && python3 ft_achievement_tracker.py
cd ex4/ && python3 ft_inventory_system.py
cd ex5/ && python3 ft_data_stream.py
cd ex6/ && python3 ft_analytics_dashboard.py
```

To lint all files:

```bash
flake8 ex0/ ex1/ ex2/ ex3/ ex4/ ex5/ ex6/
```

---

## ⚠️ Important Rules

- **Only `sys` may be imported** — no `json`, `csv`, `os`, `random`, or third-party libs
- **No file I/O** — all data in-memory or via `sys.argv`
- **No crashes** — all invalid inputs must be handled gracefully
- Show both **basic** and **advanced** usage for each data structure
- Lv.6 output does **not** need to match the example exactly — focus on comprehension clarity

---

## 🤖 AI Usage Policy

AI tools are **permitted** with the following rules:

- ✅ Use AI to explore collection methods, generator patterns, and comprehension syntax
- ✅ Only submit code you **fully understand** and can explain
- ❌ Do not copy-paste AI output without understanding it — during eval you'll be asked to extend your implementations live
- ❌ Peer evaluation will include explaining **why** you chose a list vs a set vs a dict in a given situation

> Be ready to justify every data structure choice — "it worked" is not enough.

---

## 📦 Submission

Submit all files via your **Git repository**. Only files tracked in the repo will be evaluated.

Files to submit:
- `ex0/ft_command_quest.py`
- `ex1/ft_score_analytics.py`
- `ex2/ft_coordinate_system.py`
- `ex3/ft_achievement_tracker.py`
- `ex4/ft_inventory_system.py`
- `ex5/ft_data_stream.py`
- `ex6/ft_analytics_dashboard.py`

---

*"Lists are your backpack, tuples are your armor, sets are your trophy case, dictionaries are your spell book — and generators are the magic that makes it all scale."*
