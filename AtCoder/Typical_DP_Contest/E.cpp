#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;
ll dp[10002][2][102];

int main() {
  string s;
  int d, n;
  cin >> d >> s;
  n = (int)s.size();
  dp[0][0][0] = 1;
  rep(i,n){
    rep(j, d){
      // i桁目まででNより小さいならi+1桁目は何でも良い
      rep(k,10){
        dp[i + 1][1][(j + k) % d] += dp[i][1][j];
        dp[i + 1][1][(j + k) % d] %= MOD;
      }
      int nd = s[i] - '0';
      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      rep(k, nd){
        dp[i + 1][1][(j + k) % d] += dp[i][0][j];
        dp[i + 1][1][(j + k) % d] %= MOD;
      }
      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      dp[i + 1][0][(j + nd) % d] = dp[i][0][j];
    }
  }
  cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
}