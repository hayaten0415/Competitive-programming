#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 50);

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }
  ll ans = -INF;
  vector<ll> dp(n, INF);
  rep(i, n){
    chmax(ans, A[i] - dp[i]);
    for(int v : G[i]){
      chmin(dp[v], dp[i]);
      chmin(dp[v], A[i]);
    }
  }
  cout << ans << endl;
}