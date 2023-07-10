#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N];

void down(int x)
{
    int l = 2 * x;
    int r = l + 1;

    int tmin = x;
    if (l <= n && h[l] < h[tmin])
        tmin = l;
    if (r <= n && h[r] < h[tmin])
        tmin = r;

    if (tmin != x)
    {
        swap(h[tmin], h[x]);
        down(tmin);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[n--];
        down(1);
    }

    return 0;
}