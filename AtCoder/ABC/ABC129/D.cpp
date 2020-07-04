#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  vector<vector<int>> light_row_count(h, vector<int>(w, 0));
  vector<vector<int>> light_column_count(h, vector<int>(w, 0));
  rep(i, h){
    cin >> grid[i];
  }
  int ans = 0;
  rep(i, h){
    int cn = 0;
    rep(j, w){
      if(grid[i][j] == '#'){
        cn = 0;
        continue;
      }
      cn++;
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
  rep(i,h){
    rep(j,w){
      ans = max(light_row_count[i][j] + light_column_count[i][j]-1, ans);
    }
  }
  cout << ans << endl;
}