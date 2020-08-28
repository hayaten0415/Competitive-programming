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
ll dp[1020][2];

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> sum(n);
  rep(i, n){
    rep(j, m){
      ll num;
      cin >> num;
      sum[i] += num;
    }
  }
  rep(i, n){
    rep(k, 2){
      dp[i + 1][k] = max(dp[i][k], dp[i + 1][k]);
    }
    dp[i + 1][1] = max(dp[i][0] + sum[i], dp[i + 1][1]);
    dp[i + 1][0] = max(dp[i][1] - sum[i], dp[i + 1][0]);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}