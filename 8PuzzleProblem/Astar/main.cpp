#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int g, h;
    string path;
    bool operator>(const Node& other) const {
        return g + h > other.g + other.h;
    }
};

int manhattan(vector<vector<int>>& s, vector<vector<int>>& goal) {
    int d = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (s[i][j]) {
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                        if (s[i][j] == goal[x][y])
                            d += abs(i - x) + abs(j - y);
            }
    return d;
}

string aStar(vector<vector<int>> start, vector<vector<int>> goal) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> vis;
    pq.push({start, 0, manhattan(start, goal), ""});
    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.state == goal) return cur.path;
        if (vis.count(cur.state)) continue;
        vis.insert(cur.state);
        int zx, zy;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (cur.state[i][j] == 0) zx = i, zy = j;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        char mv[4] = {'D', 'U', 'R', 'L'};
        for (int k = 0; k < 4; k++) {
            int nx = zx + dx[k], ny = zy + dy[k];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                auto ns = cur.state;
                swap(ns[zx][zy], ns[nx][ny]);
                if (!vis.count(ns))
                    pq.push({ns, cur.g + 1, manhattan(ns, goal), cur.path + mv[k]});
            }
        }
    }
    return "No solution";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3)), goal(3, vector<int>(3));
    cout << "Enter start state (3x3 with 0 for blank):\n";
    for (auto& row : start) for (auto& x : row) cin >> x;
    cout << "Enter goal state (3x3 with 0 for blank):\n";
    for (auto& row : goal) for (auto& x : row) cin >> x;
    string res = aStar(start, goal);
    cout << (res == "No solution" ? res : "Moves: " + res) << endl;
}
