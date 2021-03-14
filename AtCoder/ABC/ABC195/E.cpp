#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  string s, x;
  cin >> n >> s >> x;
  vector<vector<int>> dp(n + 1, vector<int>(7, 0));
  dp[n][0] = 1;
  int ten = 1;
  rrep(i, n){
    rep(j, 7){
      int nj = (j + ten * (s[i] - '0')) % 7;
      if(x[i] == 'T'){
        dp[i][j] = dp[i+1][j] || dp[i+1][nj];
      }else{
        dp[i][j] = dp[i + 1][j] && dp[i + 1][nj];
      }
    }
    ten *= 10;
    ten %= 7;
  }
  if(dp[0][0]){
    cout << "Takahashi" << endl;
  }else{
    cout << "Aoki" << endl;
  }
}