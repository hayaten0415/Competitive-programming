#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PP = pair<int, P>;
typedef long long ll;
bool visited[1000][1000];
int dist[1000][1000];
string grid[1000];

int h, w, sy, sx, gy, gx;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int t_dx[16] = {1, 0, -1, 0, 1, 1, -1, -1, 2, 0, -2, 0, 2, 2, -2, -2};
const int t_dy[16] = {0, 1, 0, -1, 1, -1, 1, -1, 0, 2, 0, -2, 2, -2, 2, -2};
const int INF = (1 << 30);

//二次元グリッドグラフでのダイクストラ法
void dijkstra(int y, int x){
  dist[y][x] = 0;
  priority_queue<PP, vector<PP>, greater<PP>> que;
  que.push(PP(0, P(y, x)));
  while(!que.empty()) {
    PP p = que.top();
    que.pop();
    int cy = p.second.first, cx = p.second.second;
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny < 0 || h <= ny || nx < 0 || w <= nx)continue;
      if(grid[ny][nx] == '#')continue;
      if(dist[ny][nx] <= dist[cy][cx])continue;
      dist[ny][nx] = dist[cy][cx];
      que.push(PP(dist[ny][nx], P(ny, nx)));
    }
    for (int i = cy -2; i <= cy + 2; i++){
      for (int j = cx - 2; j <= cx + 2; j++){
        if (i < 0 || h <= i || j < 0 || w <= j)continue;
        if(grid[i][j] == '#')continue;
        if(dist[i][j] <= dist[cy][cx] + 1)continue;
        dist[i][j] = dist[cy][cx] + 1;
        que.push(PP(dist[i][j], P(i, j)));
      }
    }
  }
  return;
}

int main() {
  cin >> h >> w;
  cin >> sy >> sx;
  sy--, sx--;
  cin >> gy >> gx;
  gy--; gx--;
  rep(i, h){
    rep(j, w){
      dist[i][j] = INF;
    }
  }
  rep(i, h) cin >> grid[i];
  dijkstra(sy, sx);
  if(dist[gy][gx] ==INF){
    cout << -1 << endl;
  }else{
    cout << dist[gy][gx] << endl;
  }
}