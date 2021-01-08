#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int LCS(const string &s, const string &t){
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
  return dp[n][m];
  //復元部分
  //string ans = "";
  //int i = n;
  //int j = m;
  //while(i > 0 && j > 0){
  //  if(dp[i][j] == dp[i-1][j])i--;
  //  else if(dp[i][j] == dp[i][j-1])j--;
  //  else{
  //    ans += s[i-1];
  //    i--;
  //    j--;
  //  }
  //}
  //reverse(ALL(ans));
}


int main() {
  string s, t;
  cin >> s >> t;
  int ans = LCS(s, t);
  cout << ans << endl;
}
