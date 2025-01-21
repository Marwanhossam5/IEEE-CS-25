#include <iostream>
#include <cmath>
using namespace std;

long long weights[20], total_weight, min_diff = 1e18;
int n;

void solve(int idx, long long group1_weight)
{
    if (idx == n)
    {
        long long group2_weight = total_weight - group1_weight;
        long long diff = abs(group1_weight - group2_weight);
        if (diff < min_diff)
            min_diff = diff;
        return;
    }
    solve(idx + 1, group1_weight + weights[idx]);
    solve(idx + 1, group1_weight);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        total_weight += weights[i];
    }
    solve(0, 0);
    cout << min_diff << endl;
    return 0;
}
