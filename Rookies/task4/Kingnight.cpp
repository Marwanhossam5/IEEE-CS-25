#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

pair<int, int> toCoordinates(string position)
{
    return {position[0] - 'a', position[1] - '1'};
}

int bfs(pair<int, int> start, pair<int, int> destination)
{
    if (start == destination)
        return 0;

    queue<pair<int, int>> q;
    bool visited[8][8] = {false};

    q.push(start);
    visited[start.first][start.second] = true;

    int moves = 0;

    while (!q.empty())
    {
        moves++;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<int, int> current = q.front();
            q.pop();

            for (int j = 0; j < 8; j++)
            {
                int nx = current.first + knightMoves[j][0];
                int ny = current.second + knightMoves[j][1];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny])
                {
                    if (make_pair(nx, ny) == destination)
                        return moves;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string start, destination;
        cin >> start >> destination;

        cout << bfs(toCoordinates(start), toCoordinates(destination)) << endl;
    }

    return 0;
}
