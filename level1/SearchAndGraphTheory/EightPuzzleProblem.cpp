#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string st, ed = "12345678x";

int bfs()
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<string> q;
    q.push(st);

    unordered_map<string, int> d;
    d[st] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == ed)
            return d[t];

        int k = t.find('x');
        int x = k / 3;
        int y = k % 3;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            bool inside = nx >= 0 && nx < 3 && ny >= 0 && ny < 3;

            if (inside)
            {
                string tmp = t;
                swap(tmp[k], tmp[nx * 3 + ny]);

                if (!d.count(tmp))
                {
                    d[tmp] = d[t] + 1;
                    q.push(tmp);
                }
            }
        }
    }

    return -1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        char c[2];
        cin >> c;
        st += c[0];
    }

    cout << bfs() << endl;

    return 0;
}