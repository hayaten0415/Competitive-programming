#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = (1 << 30);
ll dist[20][20];


int main() {
  rep(i, 20) rep(j, 20) dist[i][j] = INF;
  int v, e;
  cin >> v >> e;
  rep(i, e) {
    int s, t;
    ll d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }
  int n2 = (1 << v);
  ll ans = INF;
  rep(x, v){
    vector<vector<ll>> dp(n2, vector<ll>(v, INF));
    rep(i, v){
      if(i == x)continue;
      dp[i << 1][i] = dist[x][i];
    }
    rep(i, n2){
      rep(j, v){
        if(!(i >> j & 1))continue;
        rep(k, v){
          if(i >> k & 1)continue;
          chmin(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
        }
      }
    }
    chmin(ans, dp[n2 - 1][x]);
  }
  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}