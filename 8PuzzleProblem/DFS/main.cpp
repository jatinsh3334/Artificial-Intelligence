//8 Puzzle Problem using DFS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 3;
struct Node 
{
    vector<vector<int>> state;
    int x, y; 
};

void printPuzzle(vector<vector<int>> &p) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

bool isGoal(vector<vector<int>> &p)
{
    int cnt = 1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (i == N-1 && j == N-1)
            {
                return p[i][j] == 0;
            }
            if (p[i][j] != cnt++)
            {
                return false;
            }
        }
    }
    return true;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> start) 
{
    stack<Node> st;
    Node root{start, 0, 0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (start[i][j] == 0) 
            { 
                root.x = i; 
                root.y = j; 
            }
        }
    }

    st.push(root);

    while (!st.empty()) 
    {
        Node cur = st.top(); st.pop();
        printPuzzle(cur.state);
        if (isGoal(cur.state)) 
        {
            cout << "Goal state reached!" << endl;
            return;
        }

        for (int k = 0; k < 4; k++) 
        {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) 
            {
                Node next = cur;
                swap(next.state[cur.x][cur.y], next.state[nx][ny]);
                next.x = nx; next.y = ny;
                st.push(next);
            }
        }
    }
    cout << "Goal not found." << endl;
}

int main() 
{
    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    dfs(start);
    return 0;
}