# 8-Puzzle Problem using Breadth First Search (BFS)

## Aim
To implement the **8-Puzzle Problem** using **Breadth First Search (BFS)** and study its theoretical background, approach, and complexity analysis.

---

## Introduction
The **8-Puzzle Problem** is a classic problem in Artificial Intelligence. It consists of a `3 × 3` grid with 8 numbered tiles and one empty space (denoted as `0`).  
The objective is to move the tiles by sliding them into the empty space until the grid reaches the **goal state**:

1 2 3  
4 5 6  
7 8 0  

Here, `0` represents the blank tile.

---

## Problem Definition
- **Initial State:** Any valid configuration of the 8-puzzle.
- **Goal State:** Tiles ordered sequentially from `1` to `8`, with the blank (`0`) in the last position.
- **Operators:** Move the blank tile up, down, left, or right (when valid).
- **State Space:** All possible configurations of the puzzle.

---

## Approach: Breadth First Search (BFS)

1. **Representation:**
   - Each puzzle state is represented as a `3×3` matrix.
   - The blank position `(x, y)` is tracked for valid moves.

2. **BFS Strategy:**
   - Use a **queue** to explore puzzle states level by level.
   - At each step:
     - Dequeue the front state.
     - Check if it matches the goal configuration.
     - If not, generate possible next states by moving the blank tile in 4 directions.
     - Enqueue these new states if not already visited.

3. **Termination:**
   - If the goal is found, stop the search.
   - If the queue becomes empty, report "Goal not found".

---

## Example Execution

### Input Start State

1 2 3  
4 0 6  
7 5 8  

### BFS Expansion (Sample Sequence of States)

1 2 3     1 0 3     1 2 3  
4 0 6 ->  4 2 6 ->  4 6 0  
7 5 8     7 5 8     7 5 8  

The search continues **level by level**, guaranteeing the shortest path to the goal state.

---

## Time Complexity
- In the worst case, BFS may need to explore the entire state space.
- The 8-puzzle has at most `9! = 362,880` possible states.
- **Time Complexity:** O(b^d),  
  where `b` = branching factor (max 4 moves) and `d` = depth of the solution.  
  Worst case: O(9!).

---

## Space Complexity
- BFS stores all nodes at the current frontier in a queue.
- This requires significantly more memory compared to DFS.
- **Space Complexity:** O(b^d),  
  since all nodes of the current level are kept in memory.

---

## Advantages of BFS
- Always finds the **shortest solution path** (in terms of number of moves).
- Complete: if a solution exists, BFS will find it.

---

## Disadvantages of BFS
- Very high memory consumption due to storing all frontier nodes.
- May be slower in practice compared to DFS for deep solutions.

---

## Conclusion
The BFS approach to solving the 8-Puzzle problem explores states level by level using a queue. Unlike DFS, BFS guarantees finding the **shortest path** to the goal configuration, but it requires much more memory. This makes BFS an essential algorithm for studying uninformed search strategies in Artificial Intelligence.
