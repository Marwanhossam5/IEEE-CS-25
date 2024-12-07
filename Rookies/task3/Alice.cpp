#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int t[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    int alice_time = 0, bob_time = 0;
    int i = 0, j = n - 1;
    int alice_count = 0, bob_count = 0;

    while (i <= j)
    {
        if (alice_time <= bob_time)
        {
            alice_time += t[i];
            alice_count++;
            i++;
        }
        else
        {
            bob_time += t[j];
            bob_count++;
            j--;
        }
    }

    cout << alice_count << " " << bob_count << endl;

    return 0;
}
