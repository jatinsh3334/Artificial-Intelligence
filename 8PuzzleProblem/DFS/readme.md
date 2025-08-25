# 8-Puzzle Problem using Depth First Search (DFS)

## Aim
To implement the **8-Puzzle Problem** using **Depth First Search (DFS)** and study its theoretical background, approach, and complexity analysis.

---

## Introduction
The **8-Puzzle Problem** is a classic problem in Artificial Intelligence. It consists of a `3 × 3` grid with 8 numbered tiles and one empty space (denoted as `0`).  
The objective is to move the tiles by sliding them into the empty space until the grid reaches the **goal state**:

1 2 3 
4 5 6
7 8 9



Here, `0` represents the blank tile.

---

## Problem Definition
- **Initial State:** Any valid configuration of the 8-puzzle.
- **Goal State:** Tiles ordered sequentially from `1` to `8`, with the blank (`0`) in the last position.
- **Operators:** Move the blank tile up, down, left, or right (when valid).
- **State Space:** All possible configurations of the puzzle.

---

## Approach: Depth First Search (DFS)

1. **Representation:**
   - Each puzzle state is represented as a `3×3` matrix.
   - The blank position `(x, y)` is tracked for valid moves.

2. **DFS Strategy:**
   - Use a **stack** to explore puzzle states.
   - At each step:
     - Pop the top state.
     - Check if it matches the goal configuration.
     - If not, generate possible next states by moving the blank tile in 4 directions.
     - Push these new states onto the stack.

3. **Termination:**
   - If the goal is found, stop the search.
   - If the stack becomes empty, report "Goal not found".

---

## Example Execution

### Input Start State


1 2 3
4 0 6
7 5 8



### DFS Expansion (Sample Sequence of States)

1 2 3 1 0 3 1 2 3
4 0 6 -> 4 2 6 -> 4 6 0
7 5 8 7 5 8 7 5 8



The search continues until the goal state is reached (or the stack empties).

---

## Time Complexity
- In the worst case, DFS may need to explore the entire state space.
- The 8-puzzle has at most `9! = 362,880` possible states.
- **Time Complexity:** O(b^d),  
  where `b` = branching factor (max 4 moves) and `d` = depth of the solution.  
  Worst case: O(9!).

---

## Space Complexity
- DFS uses a stack to store nodes in the current search path.
- At most, the stack depth equals the maximum depth of the state tree.
- **Space Complexity:** O(bd),  
  where `d` is the depth of the search.  
  Much less than BFS, which requires storing all nodes at the current frontier.

---

## Advantages of DFS
- Memory efficient compared to BFS.
- Simple to implement.
- May quickly find solutions that are deep in the search tree.

---

## Disadvantages of DFS
- May fall into infinite loops if not handled properly (no visited state tracking).
- Does not guarantee the shortest solution path.
- Can be inefficient in practice for large state spaces.

---

## Conclusion
The DFS approach to solving the 8-Puzzle problem explores states by diving deep into the search tree using a stack. While it is memory efficient, it does not guarantee the shortest path and may revisit states if not optimized with visited sets. This implementation serves as a foundation for understanding search strategies in Artificial Intelligence.
