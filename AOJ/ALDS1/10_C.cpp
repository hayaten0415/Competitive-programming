#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  rep(i, n){
    rep(j, m){
      if(s[i] == t[j]){ 
        dp[i+1][j+ 1] = dp[i][j] + 1;
      }else{ 
          dp[i+1][j+ 1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  cout << dp[n][m] << "\n";
}

int main() {
  int q;
  cin >> q;
  rep(i, q)solve();
  return 0;
}