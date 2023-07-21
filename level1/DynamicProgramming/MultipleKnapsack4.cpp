#include <iostream>
using namespace std;

const int N = 2010;

int n, m;
int f[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);

        for (int k = 1; k <= s; k *= 2)
        {
            for (int j = m; j >= k * v; j--)
                f[j] = max(f[j], f[j - k * v] + k * w);
            s -= k;
        }
        if (s)
        {
            for (int j = m; j >= s * v; j--)
                f[j] = max(f[j], f[j - s * v] + s * w);
        }
    }

    printf("%d", f[m]);

    return 0;
}