#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int INF = (1 << 30);

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<int> sheat;
  rep(i, n){
    if(A[i] == 1)sheat.pb(i);
  }
  int k = sheat.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
  dp[0][0] = 0;
  rep(i, n){
    rep(j, k +1){
      if(dp[i][j] == INF)continue;
      chmin(dp[i + 1][j], dp[i][j]);
      if(j < k && A[i] == 0){
        chmin(dp[i + 1][j + 1], dp[i][j] + abs(sheat[j] - i));
      }
    }
  }
  cout << dp[n][k] << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}