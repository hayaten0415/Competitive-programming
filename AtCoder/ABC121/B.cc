#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()  {
    //入力を受け取る
    int N, M, C;
    cin >> N >> M >> C;

    //長さMの配列、初期値0
    vector<int> B(M, 0);
    for(int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    //N×Mの配列を作る
    //Aは、vector<int>の長さNの配列
    //これを、vector<int>(M)で初期化（長さMの配列）
    vector<vector<int>> A(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += A[i][j] * B[j];
        }
        sum += C;
        if(sum > 0) ans++;
    }

    cout << ans << endl;
}