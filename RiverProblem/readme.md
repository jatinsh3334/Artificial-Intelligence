# Grid Pathfinding with BFS (Avoiding Rivers)

## Problem Statement
We are given a **2D grid** of size `row × column`. Some cells are blocked (representing **rivers**), and the task is to find the **shortest path** from a **starting position** to a **goal position**, moving only in the 4 cardinal directions:
- **Up**
- **Down**
- **Left**
- **Right**

If a path exists, output the sequence of coordinates that form the shortest path.  
If no path exists, print **"No path is there"**.

---

##  Key Points
- **Grid size:** `row × column`
- **Obstacles:** Represented by blocked cells (rivers).
- **Valid moves:** Only up, down, left, right (no diagonals).
- **Goal:** Find the **shortest path** using **Breadth-First Search (BFS)**.

---

## Approach
1. **Input Parsing**:
   - Take `row`, `column` as grid dimensions.
   - Take `n` (number of river cells).
   - Store river cells in a `set<pair<int,int>>` for quick lookup.
   - Take `start` and `goal` coordinates.

2. **BFS Traversal**:
   - Use a `queue` for BFS.
   - Maintain a `visited` set to avoid revisiting nodes.
   - Use a `map` (`mapped`) to store **parent relationships** (for path reconstruction).

3. **State Expansion**:
   - From the current cell, try moving in all 4 directions.
   - A move is valid only if:
     - It is inside the grid.
     - It is not a river.
     - It has not been visited yet.

4. **Path Reconstruction**:
   - If the goal is found, backtrack using the `mapped` parent relationship.
   - Reverse the path to get it from `start → goal`.

5. **Output**:
   - If a path exists → print the path.
   - Otherwise → `"No path is there"`.

---


