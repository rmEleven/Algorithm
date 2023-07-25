#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], f[N];

// f[i]: 所有长度为i的上升子序列中，结尾数字的最小值
// f[i]: 严格递增(数学归纳法可证)

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int len = 0;
    f[0] = -2e9;

    for (int i = 1; i <= n; i++)
    {
        // 贪心: 对于结尾 < a[i] 的所有上升子序列，寻找结尾最大的一个

        int l = 0;
        int r = len;

        while (l < r)
        {
            int mid = l + 1 + r >> 1;
            if (f[mid] >= a[i])
                r = mid - 1;
            else
                l = mid;
        }

        len = max(len, l + 1);
        f[l + 1] = a[i];
    }

    printf("%d", len);

    return 0;
}