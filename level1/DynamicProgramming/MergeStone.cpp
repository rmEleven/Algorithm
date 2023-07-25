#include <iostream>
using namespace std;

const int N = 310;
const int INF = 2e9;

int n;
int a[N], s[N], f[N][N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r] = INF;

            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    }

    printf("%d", f[1][n]);

    return 0;
}