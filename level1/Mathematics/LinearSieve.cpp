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
            primes[cnt++] = i;

        // 删除以i为最大因数的合数
        // 要删除的合数t = 最大因数i * 质数pj
        // pj不能超过i的最小质因数 否则i就不是t的最大因数

        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
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