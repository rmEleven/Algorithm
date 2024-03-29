#include <iostream>
using namespace std;

const int N = 15000;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    scanf("%d%d", &n, &m);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);

        int k = 1;

        while (k <= s)
        {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        if (s)
        {
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }

    n = cnt;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    printf("%d", f[m]);

    return 0;
}