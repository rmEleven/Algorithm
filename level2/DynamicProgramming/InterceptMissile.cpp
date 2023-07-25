#include <iostream>
#include <sstream>
using namespace std;

const int N = 1010;

int n, a[N];
int f[N], g[N];

int main()
{
    // stringstream读取一行内容
    string line;
    getline(cin, line);
    stringstream ssin(line);
    while (ssin >> a[n])
        n++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);

    // g[i]: 每个系统拦截的最后一个导弹的高度
    //   g[i]是单调上升的(数学归纳法可证)

    // 贪心过程: 从前向后处理每个数
    //   所有系统结尾都 < a[i]: 创建新的系统
    //   存在系统结尾  >= a[i]: 放在结尾最小的那个系统里

    // 上升子序列的最长长度 = 非降序子序列的最少个数

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < cnt && a[i] > g[j])
            j++;
        g[j] = a[i];
        if (j >= cnt)
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}