#include <bits/stdc++.h>
using namespace std;

// toa do cua cac diem trong duong di
typedef pair<int, int> ii;

const int maxN = 999 + 100;

int a[maxN][maxN], m, n, r, c, d[maxN][maxN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<ii> qe;

int solve()
{
    qe.push(ii(r, c));
    d[r][c] = 0;
    a[r][c] = 1;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > n || y < 1 || y > m)
            {
                return d[u.first][u.second] + 1;
            }
            if (a[x][y] != 1)
            {
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // ma tran [nxm], bat dau tu vi tri [r, c]
    cin >> n >> m >> r >> c;

    // cout << "Nhap cac gia tri cua ma tran: "
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = solve();
    cout << ans;

    return 0;
}
