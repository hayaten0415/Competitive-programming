#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);

ll dist[8][8];

int main() {
  int n, m;
  cin >> n >> m;
  ll ans = INF;
  rep(i, n)rep(j, n)dist[i][j] = INF;
  rep(i, n)dist[i][i] = 0;
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  rep(i, n) rep(j, n) rep(k, n) chmin(dist[j][k], dist[j][i] + dist[i][k]);
  int n2 = (1 << n);
  rep(x, n){
    vector<vector<ll>> dp(n2, vector<ll>(n, INF));
    rep(i, n){
      if(i == x)continue;
      dp[i << 1][i] = dist[x][i];
    }
    rep(i, n2){
      rep(j, n){
        if(!(i >> j & 1))continue;
        rep(k, n){
          if(i >> k & 1)continue;
          chmin(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
        }
      }
    }
    chmin(ans, dp[n2 - 1][x]);
  }
  cout << ans << endl;
}