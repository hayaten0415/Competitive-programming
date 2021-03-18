#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
const ll INF = (1LL << 60);
ll dp[365][3000][3];
ll price[365][3000];

int main() {
  int n, d;
  cin >> n >> d;
  rep(i, d) rep(j, n) cin >> price[i][j];
  rep(i, d) rep(j, n) rep(k, 3) dp[i][j][k] = INF;
  rep(i, n)dp[0][i][0] = price[0][i];
  for (int i = 1; i < d; i++){
    ll mn = INF;
    rep(j, n){
      chmin(mn,min(dp[i - 1][j][0], min(dp[i-1][j][1], dp[i-1][j][2])));
    }
    rep(j, n){
      chmin(dp[i][j][0], mn + price[i][j]);
      chmin(dp[i][j][1], dp[i-1][j][0] + price[i][j] * 9 / 10);
      chmin(dp[i][j][2], min(dp[i - 1][j][1], dp[i - 1][j][2]) + price[i][j] * 7 / 10);
    }
  }
  ll ans = INF;
  rep(i, n)rep(s, 3){
    chmin(ans, dp[d - 1][i][s]);
  }
  cout << ans << endl;
}