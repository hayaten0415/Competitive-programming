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

short dp[4001][4001];

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  short ans = 0;
  rep(i, n){
    dp[i][0] = 0;
    rep(j, m){
      if(s[i] == t[j]){ 
        dp[i+1][j+ 1] = dp[i][j] + 1;
        chmax(ans, dp[i+1][j+1]);
      }else{
        dp[i + 1][j + 1] = 0;
      }
    }
  }
  cout << ans << endl;
}
