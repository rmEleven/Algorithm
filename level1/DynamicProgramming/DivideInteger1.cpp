#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1010;

int n;
int f[N];

// 完全背包问题:
// f[i][j]: 使用1到i的数字，和恰好为j的方案数
// f[i][j] = f[i - 1][j] + f[i][j - i]

int main()
{
    scanf("%d", &n);

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % MOD;
    printf("%d", f[n]);

    return 0;
}