#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    sort(prices, prices + n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int coins;
        cin >> coins;
        int left = 0, right = n - 1, count = 0;
        for (int mid; left <= right;)
        {
            mid = left + (right - left) / 2;
            if (prices[mid] <= coins)
            {
                count = mid + 1;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << count << endl;
    }

    return 0;
}
