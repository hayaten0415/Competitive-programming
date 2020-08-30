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
int n, m, d;

void wide_dfs(int y, int x, int &c, vector<string> &grid, vector<vector<bool>> &visited){
  visited[y][x] = true;
  if(x+1 >= m)return;
  if(grid[y][x+1] == '#')return;
  c++;
  wide_dfs(y, x + 1, c, grid, visited);
}
void height_dfs(int y, int x, int &c, vector<string> &grid, vector<vector<bool>> &visited){
  visited[y][x] = true;
  if(y+1 >= n)return;
  if(grid[y+1][x] == '#')return;
  c++;
  height_dfs(y + 1, x, c, grid, visited);
}

int main() {
  cin >> n >> m >> d;
  vector<string> grid(n);
  vector<vector<bool>> wide_visited(n, vector<bool>(m, false));
  vector<vector<bool>> height_visited(n, vector<bool>(m, false));
  rep(i, n) cin >> grid[i];
  int ans = 0;
  rep(i, n){
    rep(j, m){
      int num1 = 1, num2 = 1;
      if(grid[i][j] == '#')continue;
      if(!wide_visited[i][j]){
        wide_dfs(i, j, num1, grid, wide_visited);
        if(num1 >= d)ans+= (num1 -d) + 1;
      } 
      if(!height_visited[i][j]){
        height_dfs(i, j, num2, grid, height_visited);
        if(num2 >= d)ans+= (num2 -d) + 1;
      }
    }
  }
  cout << ans << endl;
}