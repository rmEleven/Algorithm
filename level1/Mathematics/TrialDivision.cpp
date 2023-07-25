#include <iostream>
using namespace std;

bool isPrime(int x)
{
    if (x < 2)
        return false;

    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        if (isPrime(x))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}