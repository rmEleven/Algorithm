#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

unordered_map<int, int> primes;

void getPrimes(int x)
{
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0)
        {
            primes[i]++;
            x /= i;
        }
    if (x > 1)
        primes[x]++;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);
        getPrimes(x);
    }

    int ans = 1;
    for (auto prime : primes)
    {
        int t = 1;
        int k = prime.second;
        while (k--)
            t = ((ll)t * prime.first + 1) % MOD;
        ans = (ll)ans * t % MOD;
    }
    printf("%d", ans);

    return 0;
}