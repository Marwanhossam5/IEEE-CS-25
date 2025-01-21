#include <iostream>
using namespace std;

void simulate(long long n)
{
    cout << n << " ";
    if (n == 1)
        return;
    if (n % 2 == 0)
        simulate(n / 2);
    else
        simulate(n * 3 + 1);
}

int main()
{
    long long n;
    cin >> n;
    simulate(n);
    cout << endl;
    return 0;
}
