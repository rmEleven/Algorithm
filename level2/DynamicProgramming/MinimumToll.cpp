#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;

int n;
int a[N][N];
int f[N][N];

int main()
{
    scanf("%d", &n);

    memset(f, 0x3f, sizeof f);
    f[0][1] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }

    printf("%d", f[n][n]);

    return 0;
}