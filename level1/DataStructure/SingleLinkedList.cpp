#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int val[N], nex[N], idx;

void addNode(int k, int x)
{
    val[idx] = x;
    nex[idx] = nex[k];
    nex[k] = idx++;
}

void delNode(int k)
{
    nex[k] = nex[nex[k]];
}

int main()
{
    idx = 1;
    nex[0] = -1;

    scanf("%d", &n);

    while (n--)
    {
        char op[2];
        int k, x;
        scanf("%s", op);

        if (op[0] == 'H')
        {
            scanf("%d", &x);
            addNode(0, x);
        }
        else if (op[0] == 'D')
        {
            scanf("%d", &k);
            delNode(k);
        }
        else if (op[0] == 'I')
        {
            scanf("%d%d", &k, &x);
            addNode(k, x);
        }
    }

    for (int i = nex[0]; i != -1; i = nex[i])
        printf("%d ", val[i]);

    return 0;
}