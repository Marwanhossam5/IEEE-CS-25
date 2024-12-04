#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int current_time = 0, max_books = 0;
    int start = 0;

    for (int end = 0; end < n; end++)
    {
        int time;
        cin >> time;
        current_time += time;

        while (current_time > t)
        {
            cin >> time;
            current_time -= time;
            start++;
        }

        max_books = max(max_books, end - start + 1);
    }

    cout << max_books << endl;

    return 0;
}
