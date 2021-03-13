#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = (1 << 30);

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> dp(h, vector<int>(w, INF));
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  if(grid[0][0] == '#')dp[0][0] = 1;
  else dp[0][0] = 0;
  rep(i, h){
    rep(j, w){
      if(j > 0){
        if(grid[i][j] != grid[i][j-1] && grid[i][j] == '#')chmin(dp[i][j], dp[i][j-1] + 1);
        else chmin(dp[i][j], dp[i][j-1]);
      }
      if(i > 0){
        if(grid[i][j] != grid[i-1][j] && grid[i][j] == '#')chmin(dp[i][j], dp[i-1][j] + 1);
        else chmin(dp[i][j], dp[i-1][j]);
      }
    }
  }
  cout << dp[h - 1][w - 1] << endl;
}