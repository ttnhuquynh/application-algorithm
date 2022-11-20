#include <bits/stdc++.h>
using namespace std;

void process2(int A[], int *M[], int N)
{
    int i, j;

    // khởi tạo M với khoảng độ dài 1
    for (i = 0; i < N; i++)
    {
        M[i][0] = A[i];
    }

    // tính M với các khoảng dài 2^j
    for (j = 1; 1 << j <= N; j++)
    {
        for (i = 0; i + (1 << j) - 1 < N; i++)
        {
            if (M[i][j - 1] < M[i + (1 << (j - 1))][j - 1])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
            // cout << i << "," << j << ":" << M[i][j] << "\n";
        }
    }
}

int main()
{

    long long result = 0;
    int i, j, k;
    int n;
    cin >> n;

    int *A;
    A = new int[n];
    for (int t = 0; t < n; t++)
        cin >> A[t];
    // for (int t = 0; t < n; t++)
    //     cout << A[t];

    int **M = new int *[n];
    for (int t = 0; t < n; t++)
    {
        M[t] = new int[n];
    }

    process2(A, M, n);

    int m;
    cin >> m;
    for (int t = 1; t <= m; t++)
    {
        cin >> i >> j;
        if(i > j){
            int a = i;
            i = j;
            j = a;
        }
        

        k = log2(j - i + 1);
        // cout << k;
        // cout << min(M[i][k], M[j - (1 << k)+1 ][k]);
        result += min(M[i][k], M[j - (1 << k) + 1][k]);
      
    }
    cout << result;
    delete[] A;
    for (int t = 0; t < n; t++)
    {
        delete[] M[t];
    }
}