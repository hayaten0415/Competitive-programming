#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int h, w, n;
const int INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(int sy, int sx, int gy, int gx, vector<string> &grid) {
  vector<vector<int>> dist(h, vector<int>(w, INF));
  dist[sy][sx] = 0;
  queue<P> que;
  que.push({sy, sx});
  bool ok = false;
  while (!que.empty()){
    if(ok)break;
    P p = que.front();
    que.pop();
    int y = p.first, x = p.second;
    rep(i, 4){
      int ny = y + dy[i], nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
      if(dist[ny][nx] != INF)continue;
      if(ny == gy && nx == gx){
        dist[gy][gx] = dist[y][x] + 1;
        ok = true;
        break;
      }
      if(grid[ny][nx] == 'X')continue;
      dist[ny][nx] = dist[y][x] + 1;
      que.push({ny, nx});
    }
  }
  return dist[gy][gx];
}

int main() {
  cin >> h >> w >> n;
  n++;
  ll ans = 0;
  vector<P> chese(n);
  vector<string> grid(h);
  rep(i, h) {
    cin >> grid[i];
  }
  rep(i, h) {
    rep(j, w) {
      if(grid[i][j] == 'S'){
        chese[0] = {i, j};
        continue;
      }
      if(grid[i][j] != '.' && grid[i][j] != 'X'){
        int num = grid[i][j] - '0';
        chese[num] = {i, j};
        continue;
      }
    }
  }
  rep(i, n - 1) {
    ans += bfs(chese[i].first, chese[i].second, chese[i + 1].first, chese[i + 1].second, grid);
  }
  cout << ans << endl;
}