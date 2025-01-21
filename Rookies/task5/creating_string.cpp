#include <iostream>
using namespace std;

string s;
bool used[8];
char current[8];
int n;
long long total = 0;

void permute(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << current[i];
        cout << endl;
        total++;
        return;
    }
    bool visited[26] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && !visited[s[i] - 'a'])
        {
            used[i] = true;
            current[idx] = s[i];
            visited[s[i] - 'a'] = true;
            permute(idx + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> s;
    n = s.size();
    permute(0);
    cout << total << endl;
    return 0;
}
