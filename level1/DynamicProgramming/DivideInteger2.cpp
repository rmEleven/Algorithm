#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1010;

int n;
int f[N][N];

// f[i][j]: 总和为i，划分成j个数字的方案数
// f[i][j] = f[i - 1][j - 1] + f[i - j][j](依据最小值是否为1分类讨论)

int main()
{
    scanf("%d", &n);

    f[0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;

    int ans = 0;
    for (int j = 1; j <= n; j++)
        ans = (ans + f[n][j]) % MOD;
    printf("%d", ans);

    return 0;
}