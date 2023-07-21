#include <iostream>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n;
int a[N][N], f[N][N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i++)
        f[i][0] = f[i][i + 1] = -INF;

    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];

    int ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    printf("%d", ans);

    return 0;
}