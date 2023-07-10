#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int node[N * 31][2];
int idx;

void insert(int x)
{
    int p = 0;

    for (int i = 30; i >= 0; i--)
    {
        int num = (x >> i) & 1;
        if (node[p][num] == 0)
            node[p][num] = ++idx;
        p = node[p][num];
    }
}

int find(int x)
{
    int ans = 0;
    int p = 0;

    for (int i = 30; i >= 0; i--)
    {
        int num = (x >> i) & 1;
        if (node[p][!num])
        {
            ans = (ans << 1) + !num;
            p = node[p][!num];
        }
        else
        {
            ans = (ans << 1) + num;
            p = node[p][num];
        }
    }

    return ans;
}

int main()
{
    scanf("%d", &n);

    int ans = 0;
    while (n--)
    {
        int x;
        scanf("%d", &x);

        int t = find(x);
        ans = max(ans, t ^ x);
        insert(x);
    }

    printf("%d", ans);

    return 0;
}