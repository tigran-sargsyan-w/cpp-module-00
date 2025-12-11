# C++ Module 00 – Basics & First Classes 💡🧱

✅ **Status**: Completed – all exercises

🏫 **School**: 42 – C++ Modules (Module 00)

🏅 Score: 100/100

> *Namespaces, classes, member functions, stdio streams, initialization lists, `static`, `const` and some other basic stuff.*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – Megaphone](#ex00--megaphone)
  * [ex01 – My Awesome PhoneBook](#ex01--my-awesome-phonebook)
  * [ex02 – The Job Of Your Dreams](#ex02--the-job-of-your-dreams)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 00 (C++98)**.
The module is the starting point of the C++ journey at 42 and focuses on:

* Getting used to **basic C++ syntax** and compilation rules
* Moving from C-style code to **C++-style code** (streams, classes, etc.)
* Writing **very small programs** that use classes, methods and simple OOP ideas

All exercises are written in **C++98** and compiled with strict flags (`-Wall -Wextra -Werror -std=c++98`).

---

## 🎯 Goals of the Module

Concepts covered (depending on the exercise):

* `std::cout` / `std::cin` and basic **iostream** usage
* Simple **namespaces**
* **Classes & objects**
* **Member functions** (methods)
* **Encapsulation** with `private` / `public`
* `static` and `const` members
* Initialization and basic **Orthodox Canonical Form** (default constructor, copy constructor, assignment, destructor) in later modules

---

## 📦 Exercises Overview

### ex00 – Megaphone

> “Just to make sure that everybody is awake…”

**Goal:**
Write a small program that takes its command-line arguments and prints them **in uppercase**.
If no argument is provided, it prints a default loud message.

**Example usage:**

```bash
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$ ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Concepts practiced:**

* `int main(int argc, char **argv)`
* Working with **C-style strings** in C++ or `std::string`
* Basic usage of **loops and character manipulation** (`std::toupper`)

---

### ex01 – My Awesome PhoneBook

> A tiny 80’s-style phonebook running in your terminal.

**Goal:**
Implement a **simple interactive phonebook** with two classes:

* `PhoneBook`

  * Stores up to **8 contacts** in an internal array (no dynamic allocation allowed)
  * When the 9th contact is added, it **overwrites the oldest** one
* `Contact`

  * Represents a single contact with fields:

    * first name
    * last name
    * nickname
    * phone number
    * darkest secret

**Commands:**

* `ADD` – add a new contact

  * Prompts the user for all 5 fields
  * No field is allowed to be empty
* `SEARCH` – list contacts in a table and show details by index

  * Table: 4 columns – index, first name, last name, nickname
  * Each column is **10 characters wide**, **right aligned**, truncated with a `.` at the end if too long
* `EXIT` – quit the program and lose all contacts (no persistence required)

**Example session (simplified):**

```bash
$ ./phonebook
Enter a command (ADD, SEARCH, EXIT):
ADD
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves C++98

Enter a command (ADD, SEARCH, EXIT):
SEARCH
|     Index|First Name| Last Name|  Nickname|
|         0|      John|       Doe|        JD|

Enter index to display: 0
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves C++98
```

**Concepts practiced:**

* Designing simple **classes**
* Access control: `private` vs `public`
* Using **member functions** to set/get data
* Formatting output with `<iomanip>` (`std::setw`, etc.)
* Basic input validation (`std::getline`)

---

### ex02 – The Job Of Your Dreams

> Rebuild a missing implementation file (`Account.cpp`) from its header and logs.

**Given files:**

* `Account.hpp` – class interface (provided by 42)
* `tests.cpp` – test harness that uses the `Account` class
* A **log file** – expected output of the tests (with timestamps)

**Goal:**
Recreate **`Account.cpp`** so that:

* The class **compiles** with `Account.hpp` and `tests.cpp`
* The program’s output **matches the reference log** (except for timestamps)
* Static members and methods correctly track global statistics

  * number of accounts
  * total amount
  * number of deposits / withdrawals
* Instance methods manage each account’s state accordingly

> Note: Destructor call order may differ slightly depending on compiler/OS, and this is acceptable.

**Concepts practiced:**

* Splitting interface (`.hpp`) and implementation (`.cpp`)
* `static` **member variables and functions**
* Understanding behavior from a **test file and log**, not just from a spec
* Working with timestamps & formatted logging (implementation-dependent)

---

## 🛠 Requirements

From the official subject:

* **Compiler**: `c++`
* **Flags**:

  * `-Wall -Wextra -Werror`
  * plus `-std=c++98`
* **OS**: any Unix-like system (Linux / macOS)
* **No external libraries** (no C++11, no Boost, etc.)
* **No `printf`, `malloc`, `free`** (and family) – use C++ stdlib instead

---

## ▶️ Build & Run

Clone the repository and build each exercise separately.

```bash
git clone <this-repo-url>
cd cpp-module-00
```

### ex00 – Megaphone

```bash
cd ex00
make
./megaphone "Hello World"
```

### ex01 – My Awesome PhoneBook

```bash
cd ex01
make
./phonebook
```

### ex02 – The Job Of Your Dreams

```bash
cd ex02
make
./accounts
```

> Exact executable names may differ depending on my implementation / subject instructions.

---

## 📂 Repository Layout

```text
cpp-module-00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
│
├── ex01/
│   ├── Makefile
│   ├── Contact.hpp / Contact.cpp
│   ├── PhoneBook.hpp / PhoneBook.cpp
│   └── main.cpp
│
└── ex02/
    ├── Makefile
    ├── Account.hpp      # provided by 42
    ├── Account.cpp      # reimplemented by me
    └── tests.cpp        # provided test harness
```

---

## 🔍 Testing Tips

Some ideas for manual testing:

* **ex00**

  * No arguments → prints the default loud message
  * Mixed case / punctuation → all converted to uppercase
* **ex01**

  * Try adding more than **8** contacts → verify that the **oldest** entries are overwritten
  * Use long names (>10 chars) → check that they are **properly truncated with `.`** in the SEARCH table
  * Enter invalid indices on SEARCH → program should handle it gracefully
* **ex02**

  * Compare output of `./accounts` with the **reference log** provided in the subject
  * Check that totals are correct when deposits and withdrawals are performed

---

## 🧾 42 Notes

* Module 00 is **introductory**; you can technically pass it without exercise 02, but implementing it is great practice.
* C++ modules **do not use Norminette** (no enforced C Norm), but clean, readable code is still strongly recommended.

---

If you’re a 42 student working on the same module, feel free to explore the code, get inspired, but **write your own implementation** – that’s where the real learning happens. 🚀
