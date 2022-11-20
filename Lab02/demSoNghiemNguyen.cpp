#include <bits/stdc++.h>

using namespace std;

int A[1000];

int x[1000];

int dem = 0;

int n, M;
int tong = 0;

// t la tong cac A[i]

int t[1000];

void initT()
{
    for (int i = 0; i < n; i++)
    {
        t[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            t[i] += A[j];
        }
    }
}
void solve(int k)
{
    // cout << t[n-1] << " " << t[k];
    int max = M - tong - (t[n - 1] - t[k]);
    // cout << max;
    for (int t = 1; t <= max / A[k]; t++)
    {
        x[k] = t;
        tong += x[k] * A[k];
        if (k == n - 1)
        {
            if (tong == M)
            {
                dem++;
            }
        }
        else
        {
            solve(k + 1);
        }
        tong -= x[k] * A[k];
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    initT();

    // for (int i = 0; i < n; i++)
    // {
    //     cout << t[i] << " ";
    // }
    solve(0);

    cout << dem;

    return 0;
}
