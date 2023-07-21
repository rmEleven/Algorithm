#include <iostream>
using namespace std;

const int N = 110;

int n, m;
int s[N], v[N][N], w[N][N];
int f[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);

        for (int j = 1; j <= s[i]; j++)
            scanf("%d%d", &v[i][j], &w[i][j]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    printf("%d", f[m]);

    return 0;
}