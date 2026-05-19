# Smart Graph Analyzer

Graph analysis framework written in C++.

## Features

- Kruskal MST
- Prim MST
- Dijkstra Shortest Path
- Random Graph Generator
- Graph Analytics
- DOT Export
- File Save / Load
- OOP Architecture

## Build

```bash
cl /EHsc /std:c++14 /Iinclude src\main.cpp src\Graph.cpp src\Algorithms.cpp src\FileManager.cpp src\Utilities.cpp
```

## Run

```bash
.\main.exe
```

## Project Structure

- include/ -> Header files
- src/ -> Source files
- datasets/ -> Input datasets
- output/ -> Generated files