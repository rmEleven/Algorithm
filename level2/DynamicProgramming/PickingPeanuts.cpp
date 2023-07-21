#include <iostream>
using namespace std;

const int N = 110;

int t, n, m;
int a[N][N], f[N][N];

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }

        printf("%d\n", f[n][m]);
    }

    return 0;
}