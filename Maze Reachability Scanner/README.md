# Maze Reachability Scanner

A grid-based pathfinding simulator using Depth First Search (DFS).

The program determines whether specific cells in a maze are reachable from a starting position.

---

# Problem Description

You are given a maze represented as a 2D grid.

Each cell contains:

- `*` → free path
- `#` → blocked cell

Starting from a given position, determine whether different target cells are reachable using 4-directional movement.

Allowed moves:

- Up
- Down
- Left
- Right

---

# Algorithms Used

- Depth First Search (DFS)
- Grid Traversal
- Recursive Search

---

# Time Complexity

DFS Traversal:

```text
O(N × M)
```

Where:
- `N` = number of rows
- `M` = number of columns

---

# Run

```bash
./maze
```

---

# Sample Input

```text
5 6
******
*##***
***#**
##****
******
0 0
4
4 5
1 1
2 2
3 0
```

---

# Sample Output

```text
YES
NO
YES
NO
```

---

# Features

- DFS-based maze exploration
- Reachability detection
- Efficient grid traversal
- Recursive graph exploration

---
