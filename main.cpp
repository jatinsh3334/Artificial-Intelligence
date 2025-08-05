#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stack>
#include<algorithm>
using namespace std;

string matrixToString(vector<vector<int>> &board) {
    string s;
    for (auto &row : board)
        for (int val : row)
            s += to_string(val);
    return s;
}

vector<vector<int>> stringToMatrix(string s) {
    vector<vector<int>> board(3, vector<int>(3));
    for (int i = 0; i < 9; i++)
        board[i / 3][i % 3] = s[i] - '0';
    return board;
}

void printBoard(vector<vector<int>> &board) {
    for (auto &row : board) {
        for (int val : row)
            cout << (val == 0 ? "  " : to_string(val) + " ");
        cout << endl;
    }
    cout << "--------\n";
}


vector<vector<int>> target = {{1,2,3},{4,5,6},{7,8,0}};

bool isGoal(vector<vector<int>> &board) {
    return board == target;
}

int bfs(vector<vector<int>> start) {
    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    string startKey = matrixToString(start);
    string goalKey = matrixToString(target);

    visited.insert(startKey);
    q.push(startKey);
    parent[startKey] = "";  

    int steps = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            string curr = q.front(); q.pop();
            if (curr == goalKey) {

                vector<string> path;
                while (!curr.empty()) {
                    path.push_back(curr);
                    curr = parent[curr];
                }

                reverse(path.begin(), path.end());

                cout << "Minimum steps to solve: " << path.size() - 1 << "\n";
                cout << "Path of steps:\n";
                for (string &state : path) {
                    vector<vector<int>> board = stringToMatrix(state);
                    printBoard(board);
                }

                return path.size() - 1;
            }


            vector<vector<int>> board = stringToMatrix(curr);
            int zx, zy;

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == 0) {
                        zx = i;
                        zy = j;
                    }

            for (int d = 0; d < 4; d++) {
                int nx = zx + dx[d];
                int ny = zy + dy[d];

                if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
                    vector<vector<int>> newBoard = board;
                    swap(newBoard[zx][zy], newBoard[nx][ny]);

                    string newKey = matrixToString(newBoard);
                    if (!visited.count(newKey)) {
                        visited.insert(newKey);
                        parent[newKey] = curr;
                        q.push(newKey);
                    }
                }
            }
        }
        steps++;
    }

    cout << "No solution found.\n";
    return -1;
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter the 3x3 matrix (use 0 for blank):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    bfs(start);
    return 0;
}
