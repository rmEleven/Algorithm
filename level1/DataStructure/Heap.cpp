#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, tail, idx;
int h[N], hp[N], ph[N];

void hpSwap(int a, int b)
{
    swap(h[a], h[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}

void down(int x)
{
    int l = 2 * x;
    int r = l + 1;

    int tmin = x;
    if (l <= tail && h[l] < h[tmin])
        tmin = l;
    if (r <= tail && h[r] < h[tmin])
        tmin = r;

    if (tmin != x)
    {
        hpSwap(tmin, x);
        down(tmin);
    }
}

void up(int x)
{
    while (x / 2 && h[x / 2] > h[x])
    {
        hpSwap(x, x / 2);
        x >>= 1;
    }
}

int main()
{
    cin >> n;

    while (n--)
    {
        string op;
        cin >> op;

        if (op == "I")
        {
            int x;
            cin >> x;

            tail++;
            idx++;

            h[tail] = x;
            hp[tail] = idx;
            ph[idx] = tail;

            up(tail);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            hpSwap(1, tail--);
            down(1);
        }
        else if (op == "D")
        {
            int k;
            cin >> k;
            k = ph[k];

            hpSwap(k, tail--);
            down(k);
            up(k);
        }
        else if (op == "C")
        {
            int k, x;
            cin >> k >> x;
            k = ph[k];

            h[k] = x;
            down(k);
            up(k);
        }
    }

    return 0;
}