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
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  // dp[i][0]ちょうど
  // dp[i][1]繰り上げ
  dp[0][1] = 1;
  rep(i, n){
    int x = s[i] - '0';
    dp[i + 1][0] = min(dp[i][0] + x, dp[i][1] + 10 - x);
    dp[i + 1][1] = min(dp[i][0] + x +1, dp[i][1] + 10 - x-1);
  }
  cout << dp[n][0] << endl;
}