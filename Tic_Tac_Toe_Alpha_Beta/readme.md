# Tic Tac Toe with Alpha-Beta Pruning

##  Overview
This project is a **C++ console-based Tic Tac Toe game** where:
- The **player (X)** competes against the **AI (O)**.
- The AI uses the **Minimax algorithm enhanced with Alpha-Beta Pruning**.
- This ensures that the AI always makes the best possible move while running faster than plain Minimax.

---

##  Theory: Minimax and Alpha-Beta Pruning

### 🔹 Minimax Algorithm
- The **Minimax algorithm** is a recursive algorithm used in **two-player games**.
- It assumes:
  - The **AI (O)** tries to **maximize** the score.
  - The **Player (X)** tries to **minimize** the score.
- Base scoring in this game:
  - `+10` → AI wins  
  - `-10` → Player wins  
  - `0`  → Draw  

The algorithm explores **all possible moves** and chooses the one that leads to the best guaranteed outcome.

---

### 🔹 Problem with Plain Minimax
- Without optimization, Minimax explores **all game states**.
- In Tic Tac Toe, this can go up to `9! = 362,880` states.
- This is manageable here, but for larger games (like Chess), it becomes **very slow**.

---

### 🔹 Alpha-Beta Pruning
Alpha-Beta Pruning is an optimization for Minimax.  

- **Alpha (α):** Best value that the **maximizer (AI)** can guarantee so far.  
- **Beta (β):** Best value that the **minimizer (Player)** can guarantee so far.  
- **Pruning condition:** If at any point `β ≤ α`, the branch is **cut off** (pruned), because it cannot affect the final decision.

This reduces the number of states explored **without changing the result**.

---

##  Code Method (How It’s Implemented)

1. **Game Setup**
   - A `3x3` board is initialized with spaces `' '`.
   - Player plays as **X**, AI plays as **O**.

2. **Check for Win**
   - A helper function `checkWin()` evaluates rows, columns, and diagonals.
   - Returns `PLAYER`, `AI`, or `0` (no winner yet).

3. **Minimax with Alpha-Beta Pruning**
   ```cpp
   int minimax(bool isAI, int alpha, int beta) {
       int score = checkWin();
       if (score == AI) return +10;
       if (score == PLAYER) return -10;
       if (!movesLeft()) return 0;

       if (isAI) { 
           int best = -1000;
           for (all empty cells) {
               place 'O';
               best = max(best, minimax(false, alpha, beta));
               undo move;
               alpha = max(alpha, best);
               if (beta <= alpha) break; 
           }
           return best;
       } else { 
           int best = 1000;
           for (all empty cells) {
               place 'X';
               best = min(best, minimax(true, alpha, beta));
               undo move;
               beta = min(beta, best);
               if (beta <= alpha) break;
           }
           return best;
       }
   }
