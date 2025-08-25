# 8 Puzzle Problem using Best-First Search

## 🎯 Aim
To solve the **8 Puzzle Problem** using the **Best-First Search (Greedy Search)** algorithm, where the next state is chosen based on a heuristic function estimating closeness to the goal state.

---

## 📖 Theory
The **8 Puzzle Problem** is a classic AI search problem consisting of a **3×3 board** with **8 numbered tiles** and **one blank space**.  
The objective is to move the tiles until reaching the **goal configuration** by sliding them into the blank.

### Best-First Search
- **Best-First Search** is a **heuristic-driven** search algorithm.  
- At each step, the node that appears to be closest to the goal (lowest heuristic cost) is expanded.  
- It uses a **priority queue** based on the heuristic value.  

### Heuristics for 8 Puzzle
- **h₁:** Number of misplaced tiles  
- **h₂:** Sum of Manhattan distances of tiles from their goal positions  

⚠️ Best-First Search **does not guarantee the shortest solution** but is faster compared to blind searches.

---

## 📝 Algorithm / Methodology
1. Represent the puzzle as a **3×3 matrix** (or a 1D array of length 9).  
2. Define a **heuristic function** for each state.  
3. Insert the **initial state** into a **priority queue** ordered by heuristic value.  
4. Repeat until the goal is found or no states remain:
   - Remove the node with the **lowest heuristic value**.  
   - If it is the **goal state**, terminate.  
   - Otherwise, generate all possible next states by moving the blank tile **(up, down, left, right)**.  
   - Push these states into the priority queue with their heuristic values.  

---

## ⏳ Time Complexity
- In the **worst case**, Best-First Search may explore a large portion of the state space.  
- The **maximum number of states** in the 8 Puzzle is `9! = 362,880`.  
- **Time Complexity:** `O(b^d)` where  
  - `b` = branching factor (≈ 2 to 4)  
  - `d` = depth of the solution  

---

## 💾 Space Complexity
- Priority queue stores all generated states until expansion.  
- **Space Complexity:** `O(b^d)` (can grow very large since multiple states are stored).  

---

## ✅ Advantages
- Faster than uninformed search algorithms.  
- Guided towards the goal using heuristics.  

## ❌ Limitations
- May **not find the optimal solution**.  
- High **space requirement** due to storing many states.  

---
