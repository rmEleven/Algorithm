#include <iostream>
using namespace std;

int Euler(int x)
{
    int ans = x;

    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
        {
            ans = ans / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        ans = ans / x * (x - 1);

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", Euler(x));
    }

    return 0;
}