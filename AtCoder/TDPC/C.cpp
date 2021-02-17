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
//dp[i][j]i番目の人がj番目のラウンドまで残っている確率
long double dp[2048][12];

int main() {
  int k;
  cin >> k;
  int n = (1 << k);
  vector<long double> R(n);
  rep(i, n) cin >> R[i];
  rep(i, n){
    dp[i][0] = 1.00L;
  }
  for (int j = 1; j <= k; j++){
    for (int i = 0; i < n; i += (1 << j)){
      for (int d = i; d < i + (1 << (j - 1)); d++){
        for (int s = i + (1 << (j - 1)); s < i +(1 << j); s++){
          long double per_s, per_d;
          if(R[s] > R[d]){
            per_d = 1.0L / (1.0L + powl(10.0L, ((R[s] - R[d]) /400.0L)));
            per_s = 1.0L - per_d;
          }else if(R[s] < R[d]) {
            per_s = 1.0L / (1.0L + powl(10.0L, ((R[d] - R[s]) /400.0L)));
            per_d = 1.0L - per_s;
          }else {
            per_d = 0.5L;
            per_s = 0.5L;
          }
          dp[s][j] += (dp[s][j - 1] * dp[d][j-1] * per_s);
          dp[d][j] += (dp[s][j - 1] * dp[d][j - 1] * per_d);
        }
      }
    }
  }
  rep(i, n){
    cout << fixed << setprecision(9) << dp[i][k] << endl;
  }
}