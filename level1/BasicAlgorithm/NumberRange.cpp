#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int findLeft(int x)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (q[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    if (q[l] == x)
        return l;
    return -1;
}

int findRight(int x)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (q[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }

    if (q[l] == x)
        return l;
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);

        printf("%d %d\n", findLeft(x), findRight(x));
    }

    return 0;
}