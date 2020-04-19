#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector<pair<int, int>> AB(N);
    for(int i = 0; i < N; i++)
    {
        AB[i] = make_pair(A[i], B[i]);
    }
    sort(AB.begin(), AB.end());

    long long ans = 0;
    for(int i = 0; i < N; i++)
    {
        int buy = min(M, AB[i].second);

        ans += (long long)buy * AB[i].first;
        M -= buy;
    }

    cout << ans << endl;
}