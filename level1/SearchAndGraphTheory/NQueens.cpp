#include <iostream>
using namespace std;

const int N = 10;

int n;
char cb[N][N];
bool col[N], dg[N * 2], udg[N * 2];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            cout << cb[i] << endl;
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        if (!col[i] && !dg[x + i] && !udg[x - i + n])
        {
            cb[x][i] = 'Q';
            col[i] = dg[x + i] = udg[x - i + n] = true;
            dfs(x + 1);
            col[i] = dg[x + i] = udg[x - i + n] = false;
            cb[x][i] = '.';
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cb[i][j] = '.';

    dfs(0);

    return 0;
}