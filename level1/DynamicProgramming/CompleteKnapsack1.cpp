#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        int v, w;
        scanf("%d%d", &v, &w);

        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v)
                f[i][j] = max(f[i][j], f[i][j - v] + w);
        }
    }

    printf("%d", f[n][m]);

    return 0;
}