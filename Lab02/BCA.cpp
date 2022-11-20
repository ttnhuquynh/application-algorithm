#include<bits/stdc++.h>
// đệ quy quay lui giống như n vòng lặp nên là phương án cuối cùng khi giải 1 bài toán

using namespace std;
#define N 50

// m giáo viên , n khóa học
int m, n;

// T[i] chứa list giáo viên có thể assign cho khóa học i
vector<int> T[N];
bool conflict[N][N];
int x[N];
int load[N];
int res;









int main(int argc, char const *argv[])
{

    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int c;
            T[c].push_back(j);
        }


    }
    
    return 0;
}
