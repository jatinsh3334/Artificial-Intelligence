#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;


vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

int calculateHeuristic(const vector<vector<int>>& state) {
    int misplaced = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] != 0 && state[i][j] != goal[i][j])
                misplaced++;
    return misplaced;
}

void printBoard(const vector<vector<int>>& board) {
    for (auto& row : board) {
        for (int val : row)
            cout << (val == 0 ? "  " : to_string(val) + " ");
        cout << endl;
    }
    cout << "-----------" << endl;
}

vector<vector<vector<int>>> generateNeighbors(vector<vector<int>> state) {
    vector<vector<vector<int>>> neighbors;
    int x, y;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0) {
                x = i;
                y = j;
            }

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

        for (auto& neighbor : neighbors) {
            int h = calculateHeuristic(neighbor);
            if (h < bestHeuristic) {
                bestHeuristic = h;
                nextState = neighbor;
            }
        }

        if (bestHeuristic >= currentHeuristic) {
            cout << "Reached local optimum or goal state.\n";
            cout << "Final state (Heuristic = " << currentHeuristic << "):\n";
            printBoard(current);
            break;
        }

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

int main() {
    vector<vector<int>> start(3, vector<int>(3));

    cout << "Enter the 3x3 puzzle (use 0 for blank space):\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> start[i][j];

    clock_t startTime = clock();
    hillClimb(start);
    clock_t endTime = clock();

    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
