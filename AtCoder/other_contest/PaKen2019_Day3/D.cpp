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
  int n;
  cin >> n;
  vector<string> grid(5);
  vector<vector<int>> dp(n, vector<int>(3, INF));
  vector<int> red(n), blue(n), white(n);
  rep(i, 5) cin >> grid[i];
  rep(i, n){
    rep(j, 5){
      if(grid[j][i] == 'R')red[i]++;
      if(grid[j][i] == 'B')blue[i]++;
      if (grid[j][i] == 'W')white[i]++;
    }
  }
  dp[0][0] = 5 - red[0];
  dp[0][1] = 5 - blue[0];
  dp[0][2] = 5 - white[0];
  rep(i, n-1){
    rep(j, 3){
      rep(k, 3){
        if(j == k)continue;
        int num;
        if(k == 0)num = red[i+1];
        if(k == 1)num = blue[i+1];
        if(k == 2)num = white[i+1];
        chmin(dp[i + 1][k], dp[i][j] + 5 - num);
      }
    }
  }
  int ans = INF;
  rep(i,3){
    chmin(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
}