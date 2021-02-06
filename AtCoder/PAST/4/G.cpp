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
int n, m;
bool visited[10][10];
vector<string> grid2(10);
vector<string> grid(10);

void dfs(int x, int y){
  visited[x][y] = true;
  rep(k, 4){
    int nx = x + dx[k], ny = y + dy[k];
    if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
    if(grid[nx][ny] == '#')continue;
    if(visited[nx][ny])continue;
    dfs(nx, ny);
  }
  return;
}

int main() {
  cin >> n >> m;
  rep(i, n) cin >> grid2[i];
  int ans = 0;
  rep(i, n)rep(j, m){
    if(grid2[i][j] == '#'){
      grid = grid2;
      grid[i][j] = '.';
      dfs(i, j);
      bool ok = true;
      rep(k, n)rep(s, m){
        if(grid[k][s] == '.' & !visited[k][s]){
          ok = false;
          break;
        }
      }
      if(ok)ans++;
      rep(k, n)rep(s, m){
        visited[k][s] = false;
      }
    }
  }
  cout << ans << endl;
}