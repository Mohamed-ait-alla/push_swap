# Push Swap

> A sorting algorithm implementation using two stacks and a limited set of operations. Developed as part of the 42 curriculum to enhance skills in algorithm design, data structures, and performance optimization.

---

## 📚 Project Overview

The goal of the **Push Swap** project is to sort a stack of integers using a predefined set of stack operations (`sa`, `pb`, `ra`, etc.), with the smallest number of moves possible. The program receives a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order.

---

## 🧠 Key Concepts

- **Stack Data Structure**
- **Sorting Algorithms (Greedy, Insertion Sort, Radix Sort, etc.)**
- **Algorithm Optimization**
- **Input Validation and Error Handling**
- **Time and Space Complexity**

---

## ⚙️ How It Works

1. The program parses and validates input.
2. The stack is initialized with the given integers.
3. A sorting algorithm is selected based on the number of elements:
   - Small inputs (3–5 numbers): Hardcoded optimal sequences
   - Large inputs: An optimized algorithm is used to minimize the total number of operations
4. Operations are executed and printed to `stdout`.

---

## 🛠️ Stack Operations Allowed

| Operation | Description                      |
|----------:|----------------------------------|
| `sa`      | Swap the top two elements of stack A |
| `sb`      | Swap the top two elements of stack B |
| `ss`      | `sa` and `sb` simultaneously      |
| `pa`      | Push the top of B onto A         |
| `pb`      | Push the top of A onto B         |
| `ra`      | Rotate A up by 1                 |
| `rb`      | Rotate B up by 1                 |
| `rr`      | `ra` and `rb` simultaneously      |
| `rra`     | Reverse rotate A by 1            |
| `rrb`     | Reverse rotate B by 1            |
| `rrr`     | `rra` and `rrb` simultaneously    |

---

## 🛠️ Usage

1. **Clone the repository And Navigate to it:**

```bash
 git clone https://github.com/Mohamed-ait-alla/push_swap.git
 cd push_swap
```

2. **Compile the source files:**
```bash
	make
```

3. **Use the format to sort your integers:**
```bash
	./push_swap <list of integers>
```
#### Example Of Usage
```bash
	$ ./push_swap 3 2 1
	sa
	rra
```

## 📁 Project Structure

```bash
push_swap/
├── Includes/
│   ├── push_swap_bonus.h
│   └── push_swap.h
│
├── bonus/
│   ├── ft_*_bonus.c
│   └── push_swap_bonus.c
│
├── get_next_line/
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
│
├── srcs/
│   ├── ft_*.c
│   └── push_swap.c
│
├── Makefile
└── README.md
```
# 🚀 Bonus

You can optionally create a checker program that validates the correctness of a given operation sequence.

## 📎 License

This project is part of the 42 School curriculum.
