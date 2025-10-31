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

### Each cell contains:

'X' → Human player

'O' → AI player

' ' → Empty cell

### Player Representation
#define HUMAN 1
#define AI 2

### Core Functions
Function	Description
initBoard()	Initializes the empty board
printBoard()	Displays the current state of the game
checkWin()	Checks whether a player has won
isMovesLeft()	Returns true if moves are still possible
evaluate()	Heuristic evaluation of the board state
AOStar()	Core AO* recursive algorithm implementing AND-OR search
bestMove()	Determines the AI’s optimal move using AO* output
Methodology

### Initialize the game board with empty cells.

The human player makes the first move (X).

The AI performs the following steps:

Evaluates all possible moves.

Constructs an AND-OR graph of possible future states.

Uses heuristic evaluation (e.g., potential win/draw chances) to rank moves.

Applies AO* recursively to expand and backtrack until the optimal move path is found.

The selected move minimizes the expected cost (chance of losing) while maximizing the chance of winning.



### Advantages of AO*

Reduces search space using heuristics.

Efficient compared to exhaustive methods like Minimax.

Can handle complex decision dependencies through AND nodes.

Adaptable to multi-step logical problems beyond games.

### Conclusion

The AO* algorithm provides a heuristic-driven, optimized approach for AI decision-making in Tic Tac Toe.
By focusing on the most promising move paths and pruning unproductive branches, it balances efficiency with accuracy — making it a powerful algorithm for game tree exploration and other AND-OR structured problems.
