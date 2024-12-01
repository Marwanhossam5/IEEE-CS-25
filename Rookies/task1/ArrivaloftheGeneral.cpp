#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int max_index = 0, min_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (array[i] > array[max_index])
        {
            max_index = i;
        }
        if (array[i] <= array[min_index])
        {
            min_index = i;
        }
    }

    int moves = max_index + (n - 1 - min_index);
    if (max_index > min_index)
    {
        moves--;
    }

    cout << moves << endl;

    return 0;
}
