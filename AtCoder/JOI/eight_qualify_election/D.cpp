#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int ans = 0;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int m, n;

void dfs(int sy, int sx, int c, vector<vector<int>> &grid, vector<vector<bool>> visited){
  visited[sy][sx] = true;
  rep(i, 4) {
    int ny = sy + dy[i], nx = sx + dx[i];
    if(ny >= n || nx >= m || ny < 0 || nx < 0){
      ans = max(ans, c);
      continue;
    }
    if(visited[ny][nx]){
      ans = max(ans, c);
      continue;
    }
    if(grid[ny][nx] == 0){
      ans = max(ans, c);
      continue;
    }
    dfs(ny, nx, c + 1, grid, visited);
  }
}

int main() {
  cin >> m >> n;
  vector<vector<int>> grid(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> grid[i][j];
    }
  }
  rep(i, n) {
    rep(j, m) {
      if(grid[i][j] == 1){
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(i, j, 1, grid, visited);
      }
    }
  }
  cout << ans << endl;
}
