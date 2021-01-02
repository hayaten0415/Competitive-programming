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
int h, w;
int r, c;
vector<string> grid;
vector<vector<int>> memo;
vector<vector<bool>> ans;
vector<vector<bool>> visited;

void dfs(int i, int j){
  if(visited[i][j])return;
  visited[i][j] = true;
  if(i > 0 && i < h){
    if (grid[i - 1][j] == '.' || grid[i - 1][j] == 'v')dfs(i-1, j);
  }
  if(i >= 0 && i < h-1){
    if (grid[i + 1][j] == '.' || grid[i + 1][j] == '^')dfs(i+1, j);
  }
  if(j >= 0 && j < w-1){
    if (grid[i][j+1] == '.' || grid[i][j+1] == '<')dfs(i, j+1);
  }
  if(j > 0 && j < w){
    if (grid[i][j-1] == '.' || grid[i][j-1] == '>')dfs(i, j-1);
  }
  return;
}

int main() {
  cin >> h >> w >> r >> c;
  r--, c--;
  grid.resize(h);
  rep(i, h) cin >> grid[i];
  memo.resize(h, vector<int>(w, 0));
  ans.resize(h, vector<bool>(w, false));
  visited.resize(h, vector<bool>(w, false));
  dfs(r,c);
  rep(i, h){
    rep(j, w){
      if(visited[i][j])ans[i][j] = true;
    }
  }
  rep(i, h){
    rep(j, w){
      if(ans[i][j])cout << "o";
      else if(grid[i][j] == '#') cout << "#";
      else cout << "x";
    }
    cout << "\n";
  }
}