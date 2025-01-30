#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
pair<int, int> start;
queue<pair<int, int>> monsters;

void bfs_monsters()
{
    while (!monsters.empty())
    {
        auto [x, y] = monsters.front();
        monsters.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && monster_time[nx][ny] == INF)
            {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                monsters.push({nx, ny});
            }
        }
    }
}

bool dfs(int x, int y, vector<vector<char>> &path, int time)
{
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
    {
        string result;
        while (path[x][y] != 'S')
        {
            result += path[x][y];
            if (path[x][y] == 'U')
                x++;
            else if (path[x][y] == 'D')
                x--;
            else if (path[x][y] == 'L')
                y++;
            else if (path[x][y] == 'R')
                y--;
        }
        reverse(result.begin(), result.end());
        cout << "YES\n"
             << result.size() << "\n"
             << result << "\n";
        return true;
    }

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && path[nx][ny] == ' ' && (monster_time[nx][ny] > time + 1))
        {
            path[nx][ny] = dir[d];
            if (dfs(nx, ny, path, time + 1))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'M')
            {
                monsters.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    bfs_monsters();
    vector<vector<char>> path(n, vector<char>(m, ' '));
    path[start.first][start.second] = 'S';

    if (!dfs(start.first, start.second, path, 0))
        cout << "NO\n";

    return 0;
}
