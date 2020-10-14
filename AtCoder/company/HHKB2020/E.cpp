#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using mint = modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  int k = 0;
  vector<string> grid(h);
  vector<vector<int>> light_row_count(h, vector<int>(w, 0));
  vector<vector<int>> light_column_count(h, vector<int>(w, 0));
  int n = h * w;
  vector<mint> two(n + 1, 1);
  rep(i, n) two[i + 1] = two[i] * 2;
  rep(i, h){
    cin >> grid[i];
  }
  rep(i, h){
    int cn = 0;
    rep(j, w){
      if(grid[i][j] == '#'){
        cn = 0;
        continue;
      }
      cn++;
      k++;
      light_row_count[i][j] += cn;
    }
  }
  rep(i, h){
    for (int j = w - 1; j > 0; j--){
      if(grid[i][j] == '#')continue;
      if(grid[i][j - 1] == '.')light_row_count[i][j - 1] = light_row_count[i][j];  
    }
  }
  rep(i, w){
    int cn = 0;
    rep(j, h){
      if(grid[j][i] == '#'){
        cn = 0;
        continue;
      }
      cn++;
      light_column_count[j][i] += cn;
    }
  }
  rep(i, w){
    for (int j = h - 1; j > 0; j--){
      if(grid[j][i] == '#')continue;
      if(grid[j-1][i] == '.')light_column_count[j-1][i] = light_column_count[j][i];
    }
  }
  mint ans = 0;
  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '#')continue;
      int tmp = light_row_count[i][j] + light_column_count[i][j] - 1;
      int x = k - tmp;
      ans += two[k];
      ans -= two[x];
    }
  }
  cout << ans.val() << endl;
}