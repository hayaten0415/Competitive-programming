#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 60);

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ans = 0;
  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  rep(i, n) dp[i][i] = A[i];
  rep(i, n){
    for (int j = i+1; j < n; j++){
      dp[i][j] = min(dp[i][j-1], A[j]);
    }
  }
  rep(i, n){
    for (int j = i; j < n; j++){
      chmax(ans, (ll)(j - i + 1) * dp[i][j]);
    }
  }
  cout << ans << endl;
}