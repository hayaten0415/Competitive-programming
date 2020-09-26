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

int main() {
    int n, k;
  cin >> n >> k;
  vector<vector<ll>> dp(n + 1, vector<ll>(5000, 0));
  dp[0][2450] = 1;
  vector<int> A(n);
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  rep(i, n){
    dp[i + 1] = dp[i];
    for (int j = 0; j <= 4900; j++){
      int j2 = j + A[i] - k;
      if (0 <= j2 && j2 <= 4900){
        dp[i + 1][j2] += dp[i][j];
      }
    }
  }
  ll ans = 0;
  ans = dp[n][2450];
  cout << ans -1 << endl;
}