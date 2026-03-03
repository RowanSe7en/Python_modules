# 🌿 CodeCultivation — Module 01

> **Object-Oriented Garden Systems**  
> *42 Network — Python Cursus*

---

## 📖 About

**CodeCultivation** is the second module of the 42 Python cursus, building directly on the fundamentals from Module 00 (*Growing Code*). You'll design a comprehensive digital garden ecosystem while mastering advanced Python concepts — from program structure and OOP basics to inheritance chains, encapsulation, and analytics platforms.

Each exercise builds on the previous one, progressively constructing a complete garden management system by the final exercise.

---

## 🗂️ Project Structure

```
module01/
├── ex0/
│   └── ft_garden_intro.py
├── ex1/
│   └── ft_garden_data.py
├── ex2/
│   └── ft_plant_growth.py
├── ex3/
│   └── ft_plant_factory.py
├── ex4/
│   └── ft_garden_security.py
├── ex5/
│   └── ft_plant_types.py
└── ex6/
    └── ft_garden_analytics.py
```

---

## 📋 Exercises Overview

| Exercise | File | Key Concept |
|----------|------|-------------|
| **Ex00** — Planting Your First Seed | `ft_garden_intro.py` | Program entry point, `__name__ == "__main__"`, variables |
| **Ex01** — Garden Data Organizer | `ft_garden_data.py` | Classes, `__init__`, object instantiation |
| **Ex02** — Plant Growth Simulator | `ft_plant_growth.py` | Instance methods, object state, behaviors |
| **Ex03** — Plant Factory | `ft_plant_factory.py` | Constructor patterns, object creation at scale |
| **Ex04** — Garden Security System | `ft_garden_security.py` | Encapsulation, getters/setters, data validation |
| **Ex05** — Specialized Plant Types | `ft_plant_types.py` | Inheritance, `super().__init__()`, polymorphism |
| **Ex06** — Garden Analytics Platform | `ft_garden_analytics.py` | Nested classes, `@classmethod`, `@staticmethod`, deep inheritance |

---

## 🔧 Technical Requirements

- **Language:** Python 3.10+
- **Linting:** All code must pass `flake8` standards
- **Naming conventions:** Classes in `PascalCase`, functions and variables in `snake_case`
- **Documentation:** Docstrings required for all classes, methods, and functions
- **Type hints:** Encouraged throughout
- **Structure:** One exercise per file; `if __name__ == "__main__":` blocks are allowed for self-testing
- Programs must always **run without errors**

---

## 📝 Exercise Details

### Ex00 — Planting Your First Seed

Understand the Python program entry point and how execution flows.

```
$> python3 ft_garden_intro.py
=== Welcome to My Garden ===
Plant: Rose
Height: 25cm
Age: 30 days
=== End of Program ===
```

Authorized: `print()`, `if __name__ == "__main__"`

> 💡 Explore: What happens if you remove the `if __name__ == "__main__":` block? Also research what a "shebang" line (`#!/usr/bin/env python3`) does.

---

### Ex01 — Garden Data Organizer

Introduce the `Plant` class as a blueprint for plant data.

```
$> python3 ft_garden_data.py
=== Garden Plant Registry ===
Rose: 25cm, 30 days old
Sunflower: 80cm, 45 days old
Cactus: 15cm, 120 days old
```

Requirements: `Plant` class with `name`, `height`, `age` attributes. Manage at least 3 plants.  
Authorized: `class`, `__init__`, `print()`

---

### Ex02 — Plant Growth Simulator

Add behaviors to `Plant` — methods that let it act on itself.

```
$> python3 ft_plant_growth.py
=== Day 1 ===
Rose: 25cm, 30 days old
=== Day 7 ===
Rose: 31cm, 36 days old
Growth this week: +6cm
```

Requirements: `grow()`, `age()`, `get_info()` methods; simulate a week of growth.  
Authorized: `class`, `__init__`, `print()`

---

### Ex03 — Plant Factory

Streamline plant creation with proper constructor initialization.

```
$> python3 ft_plant_factory.py
=== Plant Factory Output ===
Created: Rose (25cm, 30 days)
Created: Oak (200cm, 365 days)
Created: Cactus (5cm, 90 days)
Created: Sunflower (80cm, 45 days)
Created: Fern (15cm, 120 days)
Total plants created: 5
```

Requirements: At least 5 plants with varied characteristics, organized display.  
Authorized: `class`, `__init__`, `print()`

---

### Ex04 — Garden Security System

Protect plant data through encapsulation and validation.

```
$> python3 ft_garden_security.py
=== Garden Security System ===
Plant created: Rose
Height updated: 25cm [OK]
Age updated: 30 days [OK]
Invalid operation attempted: height -5cm [REJECTED]
Security: Negative height rejected
Current plant: Rose (25cm, 30 days)
```

Requirements: `SecurePlant` class with `set_height()`, `set_age()`, `get_height()`, `get_age()`. Reject negative values with an error message.  
Authorized: `class`, `__init__`, `def`, `print()`, setter/getter (custom)

---

### Ex05 — Specialized Plant Types

Model plant family relationships through inheritance.

```
$> python3 ft_plant_types.py
=== Garden Plant Types ===
Rose (Flower): 25cm, 30 days, red color
Rose is blooming beautifully!
Oak (Tree): 500cm, 1825 days, 50cm diameter
Oak provides 78 square meters of shade
Tomato (Vegetable): 80cm, 90 days, summer harvest
Tomato is rich in vitamin C
```

Class hierarchy:
```
Plant
├── Flower     → color, bloom()
├── Tree       → trunk_diameter, produce_shade()
└── Vegetable  → harvest_season, nutritional_value
```

Requirements: At least 2 instances of each type; use `super().__init__()`.  
Authorized: `class`, `__init__`, `super()`, `print()`

---

### Ex06 — Garden Analytics Platform

Bring everything together in a full analytics system with nested classes and advanced method types.

```
$> python3 ft_garden_analytics.py
=== Garden Management System Demo ===
Added Oak Tree to Alice's garden
Added Rose to Alice's garden
Added Sunflower to Alice's garden
Alice is helping all plants grow...
Oak Tree grew 1cm
Rose grew 1cm
Sunflower grew 1cm
=== Alice's Garden Report ===
Plants in garden:
- Oak Tree: 101cm
- Rose: 26cm, red flowers (blooming)
- Sunflower: 51cm, yellow flowers (blooming), Prize points: 10
Plants added: 3, Total growth: 3cm
Plant types: 1 regular, 1 flowering, 1 prize flowers
Height validation test: True
Garden scores - Alice: 218, Bob: 92
Total gardens managed: 2
```

Class hierarchy:
```
Plant → FloweringPlant → PrizeFlower
GardenManager
└── GardenStats  (nested helper class)
```

Key methods to implement:
- **Instance methods** — operate on individual garden/plant data
- **`@classmethod` `create_garden_network()`** — operates on the class itself
- **`@staticmethod`** — utility functions with no instance/class dependency

Authorized: `class`, `__init__`, `super()`, `print()`, `staticmethod()`, `classmethod()`

---

## 🧠 Concepts Introduced

| Concept | First seen |
|---------|-----------|
| `if __name__ == "__main__":` | Ex00 |
| `class` & `__init__` | Ex01 |
| Instance methods | Ex02 |
| Constructor patterns | Ex03 |
| Encapsulation / getters & setters | Ex04 |
| Inheritance & `super()` | Ex05 |
| Nested classes, `@classmethod`, `@staticmethod` | Ex06 |

---

## 🚀 Running the Exercises

Each exercise is a standalone Python program:

```bash
cd ex0/
python3 ft_garden_intro.py

cd ../ex6/
python3 ft_garden_analytics.py
```

To check linting:

```bash
flake8 ft_garden_analytics.py
```

---

## ⚠️ Important Rules

- Each exercise must be in **its own file**
- Class names in **PascalCase** (`Plant`, `SecurePlant`, `GardenManager`)
- Functions and variables in **snake_case** (`get_height`, `plant_name`)
- **Docstrings** are required for all classes and methods
- You may use `if __name__ == "__main__":` blocks for personal testing
- Input validation is only required where **explicitly mentioned** (Ex04)
- Programs must **always run without errors**

---

## 🤖 AI Usage Policy

AI tools are **permitted** with the following rules:

- ✅ Use AI to understand concepts and explore ideas
- ✅ Only submit code you **fully understand** and can explain line by line
- ❌ Do not copy-paste AI output without understanding it
- ❌ During peer evaluation, you will be asked to **explain and extend** your implementations

> Peers are your best resource — they share your environment and context. Use them as a quality checkpoint.

---

## 📦 Submission

Submit all files via your **Git repository**. Only files tracked in the repo will be evaluated.

Files to submit:
- `ex0/ft_garden_intro.py`
- `ex1/ft_garden_data.py`
- `ex2/ft_plant_growth.py`
- `ex3/ft_plant_factory.py`
- `ex4/ft_garden_security.py`
- `ex5/ft_plant_types.py`
- `ex6/ft_garden_analytics.py`

---

*"Just as a master gardener knows that healthy soil produces healthy plants, experienced programmers understand that well-structured code grows into robust applications."*
