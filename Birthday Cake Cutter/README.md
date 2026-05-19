# Birthday Cake Cutting Simulator

A dynamic simulation of cutting a rectangular birthday cake using vertical and horizontal cuts.

After each cut, the program calculates the area of the largest remaining cake piece.

---

## Problem Description

You are given a rectangular cake with width `X` and height `Y`.

Then `Q` cutting operations are performed:

- `V p` → Vertical cut at position `p`
- `H p` → Horizontal cut at position `p`

After every cut, output the area of the largest remaining rectangular piece.

---

## Example

Input:
8 6 3
V 3
H 2
V 6

Output:
30
20
12

---

## Algorithms & Data Structures

- Ordered Set (`std::set`)
- Interval Tracking
- Dynamic Geometry Simulation

---

## Time Complexity

Current implementation:
O(Q × N)

Possible optimization:
O(Q log N)

---

## Features

- Real-time rectangle splitting
- Dynamic maximum area calculation
- Efficient interval management
- Competitive programming style solution

---
