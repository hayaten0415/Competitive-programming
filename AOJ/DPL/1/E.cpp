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
const int INF = (1 << 30);

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector dp(n + 1, vector<int>(m + 1, INF));
  dp[0][0] = 0;
  rep(i, n+1){
    rep(j, m+1){
      if(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
          chmin(dp[i][j], dp[i - 1][j - 1]);
        }else{
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
      if(i > 0){
        chmin(dp[i][j], dp[i - 1][j] + 1);
      }
      if(j > 0){
        chmin(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  cout << dp[n][m] << endl;
}