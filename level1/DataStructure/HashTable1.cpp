#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n;
int h[N], val[N], nex[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;

    val[idx] = x;
    nex[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;

    for (int i = h[k]; i != -1; i = nex[i])
        if (val[i] == x)
            return true;

    return false;
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    while (n--)
    {
        char op[2];
        int x;

        scanf("%s%d", op, &x);

        if (op[0] == 'I')
            insert(x);
        else if (op[0] == 'Q')
            if (find(x))
                printf("Yes\n");
            else
                printf("No\n");
    }

    return 0;
}