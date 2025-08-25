# 8 Puzzle Problem using A* Algorithm

## Aim
To solve the 8-puzzle problem using the A* search algorithm by finding the shortest sequence of moves from an initial state to the goal state.

---

## Theory
The **8-puzzle problem** is a sliding puzzle consisting of a 3×3 grid with 8 numbered tiles and one empty space. The objective is to rearrange the tiles from a given initial state to the goal state by moving one tile at a time into the empty space.

The **A* algorithm** is a best-first search algorithm that finds the shortest path by combining:
- **g(n):** Cost from the start node to the current node.  
- **h(n):** Heuristic estimate of the cost from the current node to the goal.  
- **f(n) = g(n) + h(n):** Total cost function used to prioritize nodes.

Common heuristic functions:
1. **Misplaced Tile Heuristic** – Counts the number of tiles not in their correct position.  
2. **Manhattan Distance Heuristic** – Sums the distances of each tile from its correct position.  

The A* algorithm guarantees an optimal solution if the heuristic is **admissible** (never overestimates the true cost).

---

## Data Representation
- **State Representation:** A 3×3 matrix representing tile positions (0 denotes the empty space).  
- **Node Structure:**  
  - Current state (matrix)  
  - Parent pointer (to reconstruct the solution path)  
  - g(n), h(n), f(n) values  

---

## Methodology
1. Represent the initial and goal state as matrices.  
2. Define the heuristic function (`h(n)`) — either misplaced tiles or Manhattan distance.  
3. Insert the initial state into a priority queue (min-heap) with priority `f(n)`.  
4. While the queue is not empty:  
   - Extract the node with the smallest `f(n)`.  
   - If it matches the goal state, return the solution path.  
   - Otherwise, generate all valid child states by sliding tiles.  
   - Compute g(n), h(n), f(n) for each child.  
   - Insert children into the priority queue if not already visited.  
5. Repeat until the goal is reached.

---

## Time Complexity
- In the **worst case**, A* may expand all possible states.  
- The 8-puzzle has **9! = 362,880 states**.  
- **Time Complexity:** `O(b^d)`  
  - **b:** Branching factor (≈ 2–4 for this problem)  
  - **d:** Depth of the solution (number of moves)  
- Practically, complexity depends on the heuristic:  
  - Misplaced Tiles: Faster but less accurate  
  - Manhattan Distance: Slower but more optimal  

---

## Space Complexity
- Stores all generated states in the priority queue and visited set.  
- **Space Complexity:** `O(b^d)` in the worst case.  
- Requires significant memory since A* keeps track of explored nodes.

---

## Conclusion
The A* algorithm efficiently solves the 8-puzzle problem by using heuristics to guide the search. It guarantees the shortest solution path when an admissible heuristic (like Manhattan distance) is used, but requires considerable time and space for deeper searches.
