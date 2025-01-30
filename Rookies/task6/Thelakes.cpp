#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// IEEE

vector<vector<int>> mp;
vector<vector<int>> vis;
long long n, m, x = 0;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || mp[i][j] == 0)
    {
        return;
    }

    vis[i][j] = 1;
    x += mp[i][j];

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t, res;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        res = 0;

        mp.resize(n);
        vis.resize(n);

        for (int i = 0; i < n; i++)
        {
            mp[i].resize(m);
            vis[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    x = 0;
                    dfs(i, j);
                    res = max(res, x);
                }
            }
        }

        cout << res << '\n';
        vis.clear();
    }
}