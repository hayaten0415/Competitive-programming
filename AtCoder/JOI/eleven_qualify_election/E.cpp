#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int h, w;
const int INF = (1 << 30);
const int dx[2][6] = {{-1, 0, 1, 0, -1, -1}, {0, 1, 1, 1, 0, -1}};
const int dy[6] = {-1, -1, 0, 1, 1, 0};
int grid[110][110];
bool visited[110][110];
ll ans = 0;

void dfs(int sy, int sx){
  if(visited[sy][sx]) return;
  visited[sy][sx] = true;
  rep(i, 6) {
    int ny = sy + dy[i], nx = sx + dx[sy % 2][i];
    if(ny > h + 1 || nx > w + 1 || ny < 0 || nx < 0)continue;
    if(visited[ny][nx])continue;
    if(grid[ny][nx] == 1){
      ans++;
      continue;
    }
    dfs(ny, nx);
  }
}

int main() {
  cin >> w >> h;
  rep(i, h) {
    rep(j, w) {
      cin >> grid[i +1][j +1];
      visited[i+1][j +1] = false;
    }
  }
  dfs(0, 0);
  cout << ans << endl;
}