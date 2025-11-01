# Hill Climbing Algorithm for 8-Puzzle Problem

## Overview
This project implements the **Hill Climbing algorithm** to solve the classic **8-Puzzle problem**. The program takes an initial 3×3 board configuration and attempts to reach the goal state using a heuristic-based approach. It demonstrates the use of **local search techniques** and the concept of **heuristic optimization** in Artificial Intelligence.

---

## What is the 8-Puzzle Problem?
The 8-puzzle consists of a 3×3 grid containing eight numbered tiles and one blank space (represented by 0). The objective is to rearrange the tiles to match the **goal state** by sliding tiles horizontally or vertically into the blank space.

### Goal State
```
1 2 3
4 5 6
7 8 0
```

The state can be represented as a 2D matrix where `0` denotes the blank tile.

---

## Hill Climbing Algorithm – Theory

### Concept
Hill Climbing is a **heuristic search algorithm** that starts from an initial solution and iteratively moves towards better solutions by selecting neighboring states with a lower heuristic value. It aims to **minimize the heuristic function** until no improvement is possible.

It is called *“Hill Climbing”* because the algorithm continuously moves uphill on the cost function (or downhill for heuristic minimization) until it reaches a **peak** (local optimum).

### Characteristics
- **Local Search Algorithm:** Does not explore the complete search space.  
- **Heuristic-Driven:** Uses an evaluation function (heuristic) to measure the quality of states.  
- **Greedy Approach:** Chooses the best immediate move without considering future possibilities.  

### Advantages
- Simple and easy to implement.  
- Efficient for small search spaces or near-optimal initial states.  

### Disadvantages
- May get stuck in **local maxima/minima**.  
- No guarantee of finding the global optimum.  
- Sensitive to the initial state.

---

## Heuristic Function (Evaluation Criteria)
The heuristic used in this program is **“Number of Misplaced Tiles”**, meaning it counts how many tiles are not in their correct positions compared to the goal state.

For example:
```
Current State:
1 2 3
4 5 6
0 7 8

Heuristic Value = 2
```
(Only tiles 7 and 8 are misplaced.)

---

## Working of the Program

### Steps of the Algorithm
1. Start with an initial 3×3 board configuration.  
2. Compute the heuristic value of the current state.  
3. Generate all possible neighboring states by moving the blank space in all directions (up, down, left, right).  
4. Select the neighbor with the **lowest heuristic** value.  
5. If no neighbor has a better heuristic, stop — the algorithm has reached a **local optimum or the goal state**.  
6. Otherwise, move to the new state and repeat the process.

---

## Code Explanation

### 1. Goal Definition
```
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};
```
Defines the target configuration of the puzzle.

### 2. Heuristic Evaluation
```
int calculateHeuristic(const vector<vector<int>>& state) {
    int misplaced = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] != 0 && state[i][j] != goal[i][j])
                misplaced++;
    return misplaced;
}
```
Counts the number of misplaced tiles.

### 3. Generating Neighbors
```
vector<vector<vector<int>>> generateNeighbors(vector<vector<int>> state) {
    vector<vector<vector<int>>> neighbors;
    int x, y;

    // Find blank (0) position
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0) {
                x = i; y = j;
            }

    // Move blank tile in four directions if possible
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            vector<vector<int>> newState = state;
            swap(newState[x][y], newState[nx][ny]);
            neighbors.push_back(newState);
        }
    }
    return neighbors;
}
```
Generates all possible neighboring configurations by swapping the blank tile.

### 4. Hill Climbing Logic
```
void hillClimb(vector<vector<int>> start) {
    vector<vector<int>> current = start;
    int currentHeuristic = calculateHeuristic(current);

    cout << "Initial State (Heuristic = " << currentHeuristic << "):\n";
    printBoard(current);

    int steps = 0;
    while (true) {
        vector<vector<vector<int>>> neighbors = generateNeighbors(current);
        vector<vector<int>> nextState = current;
        int bestHeuristic = currentHeuristic;

        // Select the best neighboring state
        for (auto& neighbor : neighbors) {
            int h = calculateHeuristic(neighbor);
            if (h < bestHeuristic) {
                bestHeuristic = h;
                nextState = neighbor;
            }
        }

        // Check for local optimum
        if (bestHeuristic >= currentHeuristic) {
            cout << "Reached local optimum or goal state.\n";
            printBoard(current);
            break;
        }

        // Move to better state
        current = nextState;
        currentHeuristic = bestHeuristic;
        steps++;

        cout << "Step " << steps << " (Heuristic = " << currentHeuristic << "):\n";
        printBoard(current);

        if (currentHeuristic == 0) {
            cout << "Goal reached in " << steps << " steps!\n";
            break;
        }
    }
}
```

---

## Sample Input and Output

### Input
```
Enter the 3x3 puzzle (use 0 for blank space):
1 2 3
4 5 6
7 0 8
```

### Output
```
Initial State (Heuristic = 1):
1 2 3
4 5 6
7   8
-----------
Step 1 (Heuristic = 0):
1 2 3
4 5 6
7 8  
-----------
Goal reached in 1 steps!
Time taken: 0.00002 seconds
```

---

## Limitations
- The algorithm may **get stuck in a local minimum** (unsolvable position).  
- It does not use backtracking or randomness to escape traps.  
- Better performance can be obtained using **Simulated Annealing** or **Genetic Algorithms**.

---

## How to Run
1. Save the C++ code into a file named `hill_climbing_8_puzzle.cpp`.
2. Compile the program:
   ```
   g++ hill_climbing_8_puzzle.cpp -o hill
   ```
3. Run the executable:
   ```
   ./hill
   ```

---

## Future Improvements
- Implement **Random Restart Hill Climbing** to escape local minima.  
- Add visualization for better understanding of state transitions.  
- Integrate **A* search** for optimal pathfinding comparison.

---

## References
- Russell & Norvig, *Artificial Intelligence: A Modern Approach*  
- Rich & Knight, *Artificial Intelligence*  
- AI course notes on Search Algorithms and Heuristic Optimization.
```
