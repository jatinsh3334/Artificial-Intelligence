# Tic Tac Toe using AO* (And-Or Star) Algorithm

## Aim
To implement the Tic Tac Toe game in C++ where a human player competes against an AI opponent that uses the **AO\*** (**And-Or Star**) Algorithm — a **heuristic search algorithm** — for optimal decision-making in game tree exploration.

---

## Theory

### Game Theory
Game Theory studies strategies in competitive situations where multiple players interact under defined rules.  
In **Tic Tac Toe**, two players alternately place their symbols (X and O) on a 3×3 grid, aiming to form a line of three.  
The game is **deterministic**, **finite**, and **zero-sum**, meaning one player's gain is another's loss.

### AO* Algorithm
The **AO\*** (And-Or Star) Algorithm is an **informed search algorithm** used to solve problems represented as **AND-OR graphs**, commonly found in problem-solving and game-playing scenarios.

Unlike Minimax, which exhaustively explores all possible moves, AO\* uses **heuristic evaluation** to selectively explore the most promising paths, improving efficiency.

#### Key Concepts:
- **OR nodes** represent *decision points* (choose one among possible actions).  
- **AND nodes** represent *composite conditions* (all sub-actions must succeed).  
- AO\* works by finding the **least-cost solution graph**, updating costs using heuristics and backtracking as better solutions are found.

#### AO* Working Steps:
1. Start from the **root node** (initial board state).  
2. Expand nodes using possible player moves.  
3. Compute heuristic values for each leaf node.  
4. Propagate heuristic costs backward:
   - For **OR nodes**: choose the *minimum-cost* child.  
   - For **AND nodes**: sum up the *costs of all child nodes*.  
5. Continue expansion until an optimal path (winning or drawing sequence) is identified.

The algorithm stops when the **root node** becomes a **solved node**, representing the best strategy.

---

## Data Representation

### Board Representation
- **3×3 matrix** representing the game state:
  ```cpp
  char board[3][3];
