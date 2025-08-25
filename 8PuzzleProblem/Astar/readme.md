# 8-Puzzle Problem using A* Search Algorithm

## Aim
To solve the classic **8-puzzle problem** using the **A\* search algorithm** with the **Manhattan Distance heuristic**, ensuring the optimal solution path is found efficiently.

---

## Problem Statement
The **8-puzzle problem** consists of a 3x3 grid with **8 numbered tiles (1–8)** and one **blank space (0)**.  
The objective is to move the tiles by sliding them into the blank space to reach the **goal state**:

Goal State:
1 2 3
4 5 6
7 8 0


---

## Approach
We use the **A\* Search Algorithm**, a best-first search technique guided by the evaluation function:

f(n) = g(n) + h(n)



- **g(n):** Cost to reach the current state from the start state (number of moves made so far).  
- **h(n):** Estimated cost to reach the goal from the current state, given by the **Manhattan Distance heuristic**.  

### Manhattan Distance Heuristic
The Manhattan distance is the sum of absolute differences between the current position of a tile and its target position:


h(n) = Σ |x1 - x2| + |y1 - y2|


This heuristic is:
- **Admissible:** Never overestimates the cost.  
- **Consistent:** Guarantees optimality with A\*.  

---

## Time Complexity
- In the **worst case**, A\* explores almost all possible states.  
- The maximum number of states in the 8-puzzle = **9! = 362,880**.  
- So worst-case **Time Complexity = O(9!) ≈ O(362,880)**.  
- In practice, A\* with a heuristic prunes many paths, so it is much faster than blind search.

---

## Space Complexity
- A\* maintains an **open list** (priority queue) and a **closed set** (visited states).  
- Both can store up to **O(9!)** states in the worst case.  
- Therefore, **Space Complexity = O(9!)**.  

---

## Advantages of A*
- Guarantees the **shortest path** if the heuristic is admissible.  
- Faster than BFS or DFS for this problem.  
- Uses heuristics to intelligently guide the search.

---

## Limitations
- High memory consumption due to maintaining open and closed lists.  
- Performance degrades for larger puzzles (e.g., 15-puzzle, 24-puzzle).

---

## Conclusion
The A\* algorithm with the Manhattan Distance heuristic is an **efficient and optimal solution** for solving the 8-puzzle problem. While it has exponential worst-case complexity, it significantly reduces search time compared to brute-force methods by leveraging heuristics.

---
