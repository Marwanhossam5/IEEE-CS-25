#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int house[n], cell[m];
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> cell[i];
    }

    int max_d = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = m - 1, min_d = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            min_d = min(min_d, abs(cell[mid] - house[i]));
            if (cell[mid] > house[i])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        max_d = max(max_d, min_d);
    }

    cout << max_d << endl;
    return 0;
}
