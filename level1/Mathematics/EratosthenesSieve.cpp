#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int cnt, primes[N];
bool st[N];

void getPrimes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    getPrimes(n);
    printf("%d", cnt);

    return 0;
}