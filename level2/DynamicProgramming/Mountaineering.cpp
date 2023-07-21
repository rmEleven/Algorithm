#include <iostream>
using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }

    for (int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for (int j = n; j > i; j--)
            if (a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] + g[i] - 1);
    printf("%d", ans);

    return 0;
}