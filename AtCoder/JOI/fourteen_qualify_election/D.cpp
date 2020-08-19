#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const long long INF = (1LL << 60);

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> D(n), C(m);
  vector<vector<ll>> dp(n+1, vector<ll>(m+1,INF));
  int mergin = m - n;
  dp[0][0] = 0;
  rep(i, n) cin >> D[i];
  rep(i, m) cin >> C[i];
  rep(i, n) {
    rep(j, m) {
      if(j -i < 0)continue;
      if(j - i < mergin){
        dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
      }
      dp[i + 1][j + 1] = min(dp[i][j] + D[i] * C[j], dp[i + 1][j + 1]);
    }
  }
  ll ans = INF;
  rep(i, m + 1) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
}