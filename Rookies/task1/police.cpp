#include <iostream>
using namespace std;

int main()
{
    int n, event, free = 0, unfor = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> event;
        if (event < 0)
        {
            if (free)
            {
                free--;
            }
            else
            {
                unfor++;
            }
        }
        else
        {
            free = free + event;
        }
    }
    cout << unfor;

    return 0;
}