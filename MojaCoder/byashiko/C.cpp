#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll dp[100002][3];

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  rep(i, n)rep(j, min(i + 1, 3)){
    if(j < 2){
      chmax(dp[i + 1][j + 1], dp[i][j] + A[i]);
    }
    chmax(dp[i + 1][0], dp[i][j]);
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}