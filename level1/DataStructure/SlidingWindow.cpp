#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N];
int q[N], head, tail = -1;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    {
        if (head <= tail && i - m + 1 > q[head])
            head++;
        while (head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
        if (i - m + 1 >= 0)
            printf("%d ", a[q[head]]);
    }
    printf("\n");

    head = 0, tail = -1;
    for (int i = 0; i < n; i++)
    {
        if (head <= tail && i - m + 1 > q[head])
            head++;
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        if (i - m + 1 >= 0)
            printf("%d ", a[q[head]]);
    }

    return 0;
}