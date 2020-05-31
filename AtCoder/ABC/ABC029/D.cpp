#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;

ll dp[11][2][11];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0][0] = 1;
  rep(i,n){
    rep(j,10){
      dp[i + 1][1][j] += dp[i][1][j] * 9;
      dp[i + 1][1][j + 1] += dp[i][1][j];

      int nd = s[i] - '0';
      if(nd > 1){
        dp[i + 1][1][j] += dp[i][0][j] * (nd - 1);
        dp[i + 1][1][j + 1] += dp[i][0][j];
      }else if(nd ==1){
        dp[i + 1][1][j] += dp[i][0][j];
      }
      if(nd == 1){
        dp[i + 1][0][j + 1] = dp[i][0][j];
      }else {
        dp[i + 1][0][j] = dp[i][0][j];
      }
    }
  }
  ll ans = 0;
  rep(j,10){
    ans += (dp[n][0][j] + dp[n][1][j]) * j;
  }
  cout << ans << endl;
}