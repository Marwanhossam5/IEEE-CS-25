#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int cum_sum[n + 1] = {0};
    for (int i = 1; i <= n; ++i)
    {
        cum_sum[i] = cum_sum[i - 1] + a[i - 1];
    }

    int max_books = 0;
    for (int i = 1; i <= n; ++i)
    {
        int left = i, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (cum_sum[mid] - cum_sum[i - 1] <= t)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        max_books = max(max_books, left - i);
    }

    cout << max_books << endl;

    return 0;
}