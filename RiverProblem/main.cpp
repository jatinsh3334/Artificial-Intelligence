#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

bool isvalid(int x, int y, int row, int col, set<pair<int, int>> &blocked, set<pair<int, int>> &visited)
{
    if (x < 0 || x >= row || y < 0 || y >= col)
        return false;

    if (blocked.count({x, y}))
        return false;

    if (visited.count({x, y}))
        return false;

    return true;
}

int main()
{
    int row;
    int column;
    int n;

    cout << "Please enter the number of rows in your grid" << endl;
    cin >> row;

    cout << "Please enter the number of columns in your grid" << endl;
    cin >> column;

    cout << "Please enter the number of spots that includes river" << endl;
    cin >> n;

    set<pair<int, int>> set_to_track;

    for (int i = 0; i < n; i++)
    {
        int a;
        int b;

        cout << "Enter the first value of " << i + 1 << " element of the set" << endl;
        cin >> a;

        cout << "Enter the second value of " << i + 1 << " element of the set" << endl;
        cin >> b;

        set_to_track.insert({a, b});
    }

    pair<int, int> start;
    pair<int, int> goal;

    cout << "Enter starting position" << endl;
    cin >> start.first >> start.second;

    cout << "Enter ending position" << endl;
    cin >> goal.first >> goal.second;

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    map<pair<int, int>, pair<int, int>> mapped;

    q.push(start);
    visited.insert(start);

    mapped[start] = {-1, -1};

    bool found = false;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        // FIX: compare with goal, not 'end'
        if (current == goal)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (isvalid(nx, ny, row, column, set_to_track, visited))
            {
                q.push({nx, ny});
                visited.insert({nx, ny});
                mapped[{nx, ny}] = current;
            }
        }
    }




    if (!found)
    {
        cout << "No path is there" << endl;
    }






    else
    {
        vector<pair<int, int>> path;


        pair<int, int> current_stand = goal;



        while (current_stand != make_pair(-1, -1))
        {

            path.push_back(current_stand);
            current_stand = mapped[current_stand];
        }



        reverse(path.begin(), path.end());



        cout << "The shortest path is :" << endl;


        for (auto &p : path)
        {
            cout << "(" << p.first << "," << p.second << ") ";
        }

        
        cout << endl;
    }

    return 0;
}
