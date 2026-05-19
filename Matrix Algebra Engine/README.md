# Matrix Algebra Engine

A modern C++ matrix library built using templates,
STL vectors, and operator overloading.


## Features

- Matrix Addition
- Matrix Subtraction
- Matrix Multiplication
- Matrix Transpose
- Identity Matrix
- Exception Handling
- Template-Based Design

---
# Run

```bash
./MatrixEngine
```

---

# Example Usage

## Input

```text
Matrix A:
1 2
3 4

Matrix B:
5 6
7 8
```

---

## Output

```text
A + B:

       6       8
      10      12

A * B:

      19      22
      43      50
```

---
## Why STL Vector?

Using STL vectors provides:

- Automatic memory management
- Dynamic resizing
- Safer memory handling
- Cleaner implementation

---

# Testing

Basic unit-style tests are included in:

```bash
tests/matrix_tests.cpp
```

---

# Complexity Analysis

Addition: O(n²) 
Subtraction: O(n²) 
Multiplication: O(n³) 
Transpose: O(n²) 

---

