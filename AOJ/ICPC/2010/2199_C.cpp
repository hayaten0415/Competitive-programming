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
const ll INF = (1LL << 60);
vector<int> res;

void solve(int n, int m){
  vector<vector<ll>> dp(n + 1, vector<ll>(256, INF));
  vector<int> X(n + 1);
  vector<int> C(m);
  rep(i, m) cin >> C[i];
  rep(i, n) cin >> X[i + 1];
  dp[0][128] = 0;
  rep(i, n){
    rep(k, 256){
      rep(s, m){
        if(k + C[s] < 0){
          chmin(dp[i + 1][0], dp[i][k] + (ll)pow(X[i + 1], 2));
          continue;
        }
        if(k + C[s] > 255){
          chmin(dp[i + 1][255], dp[i][k] + (ll)pow(255 - X[i + 1], 2));
          continue;
        }
        chmin(dp[i + 1][k + C[s]], dp[i][k] + (ll)pow(k + C[s] - X[i + 1], 2));
      }
    }
  }
  ll ans = INF;
  rep(i, 256){
    chmin(ans, dp[n][i]);
  }
  res.emplace_back(ans);
}

int main() {
  while (true){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    solve(n, m);
  }
  rep(i, res.size()){
    cout << res[i] << endl;
  }
}