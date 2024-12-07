#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int left = 0, max_team_size = 0;

    for (int right = 0; right < n; right++)
    {
        while (a[right] - a[left] > 5)
        {
            left++;
        }
        max_team_size = max(max_team_size, right - left + 1);
    }

    cout << max_team_size << endl;

    return 0;
}
