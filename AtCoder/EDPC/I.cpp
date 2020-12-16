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
  int n;
  cin >> n;
  vector<long double> P(n), B(n);
  rep(i, n){
    cin >> P[i];
    B[i] = 1.00 - P[i];
  }
  vector<vector<long double>> dp(n + 1, vector<long double>(n + 1));
  dp[0][0] = (long double)1.00;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= i; j++){
      if(j > 0)dp[i][j] = dp[i-1][j] * B[i-1] + dp[i-1][j-1] * P[i-1];
      else dp[i][j] = dp[i-1][j] * B[i-1];
    }
  }
  long double ans = 0.00;
  rep(i, (n + 1) / 2){
    ans += dp[n][n - i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}