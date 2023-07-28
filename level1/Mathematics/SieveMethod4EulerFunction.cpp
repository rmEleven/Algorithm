#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

int cnt, primes[N];
bool st[N];
int phi[N];

void getPhi(int n)
{
    phi[1] = 1;
    st[1] = true;

    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }

        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[i * primes[j]] = true;

            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getPhi(n);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += phi[i];
    printf("%lld", ans);

    return 0;
}