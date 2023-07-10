#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
char str[N];

int idx;
int node[N][26];
int cnt[N];

void insert()
{
    int p = 0;

    for (int i = 0; str[i]; i++)
    {
        int num = str[i] - 'a';
        if (node[p][num] == 0)
            node[p][num] = ++idx;
        p = node[p][num];
    }

    cnt[p]++;
}

int find()
{
    int p = 0;

    for (int i = 0; str[i]; i++)
    {
        int num = str[i] - 'a';
        if (node[p][num] == 0)
            return 0;
        p = node[p][num];
    }

    return cnt[p];
}

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);

        if (op[0] == 'I')
            insert();
        else if (op[0] == 'Q')
            printf("%d\n", find());
    }

    return 0;
}