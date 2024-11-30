#include <iostream>
using namespace std;

bool isLucky(int n)
{
    while (n)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool isAlmostLucky(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (isLucky(i) && n % i == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    if (isAlmostLucky(n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
