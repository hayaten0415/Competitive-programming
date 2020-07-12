#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n, vector<ll>(13, 0));
  reverse(s.begin(), s.end());
  if(s[0] == '?'){
    rep(i, 10){
      dp[0][i] = 1;
    }
  }else{
    int num = s[0] - '0';
    dp[0][num] = 1;
  }
  int num =1;
  for (int i = 1; i < n; i++){
    //10と13は互いに素だからできる→いややっぱ関係ない
    num *= 10;
    num %= 13;
    if(s[i] == '?'){
      rep(j,10){
        rep(k, 13){
          int ind = (k + num * j) % 13;
          dp[i][ind] += dp[i - 1][k];
          dp[i][ind] %= MOD;
        }
      }
    }else{
      rep(k, 13){
        int mod = s[i] - '0';
        int ind = (k + num * mod) % 13;
        dp[i][ind] = dp[i - 1][k];
        dp[i][ind] %= MOD;
      }
    }
  }
  cout << dp[n - 1][5] << endl;
}
