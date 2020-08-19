#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
ll dp[3030][3030][4];
ll T[3030][3030];

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  rep(i, K) {
    int r, c;
    ll v;
    cin >> r >> c >> v;
    r--, c--;
    T[r][c] = v;
  }
  rep(i, R) {
    rep(j, C) {
      for(int k = 2; k >= 0; k--){
        dp[i][j][k + 1] = max(dp[i][j][k] + T[i][j], dp[i][j][k+1]);
      }
      rep(k, 4) {
        dp[i][j + 1][k] = max(dp[i][j][k], dp[i][j + 1][k]);
        dp[i+1][j][0] = max(dp[i][j][k], dp[i+1][j][0]);
      }
    }
  }
  ll ans = 0;
  rep(i, 4) {
    ans = max(ans, dp[R-1][C-1][i]);
  }
  cout << ans << endl;
}
