#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PP = pair<long long, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 10000000000000;
int h, w;
vector<vector<P>> A(26);
vector<string> grid(2000);
ll dist[2005][2005];
int gy, gx;

void dijkstra(int sy, int sx){
  dist[sy][sx] = 0;
  queue<P> que;
  que.push(P(sy, sx));
  while(!que.empty()) {
    P p = que.front();
    que.pop();
    int cy = p.first, cx = p.second;
    if(dist[gy][gx] != INF)return;
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny < 0 || h <= ny || nx < 0 || w <= nx)continue;
      if(grid[ny][nx] == '#')continue;
      if(dist[ny][nx] != INF)continue;
      dist[ny][nx] = dist[cy][cx] + 1;
      que.push(P(ny, nx));
    }
    if(grid[cy][cx] != 'S' && grid[cy][cx] != 'G' && grid[cy][cx] != '#' && grid[cy][cx] != '.'){
      int a = grid[cy][cx] - 'a';
      int ty, tx;
      for (auto k : A[a]){
        if (k == P(cy, cx))continue;
        ty = k.first, tx = k.second;
        if(dist[ty][tx] == INF){
          dist[ty][tx] = dist[cy][cx] + 1;
          que.push(P(ty, tx));
        }
      }
    }
  }
}



int main() {
  cin >> h >> w;  
  rep(i, h) cin >> grid[i];
  int sy, sx;
  rep(i, h){
    rep(j,w){
      if(grid[i][j] == 'S'){
        sy = i;
        sx = j;
        continue;
      }
      if(grid[i][j] == 'G'){
        gy = i;
        gx = j;
        continue;
      }
      if(grid[i][j] == '#')continue;
      if(grid[i][j] == '.')continue;
      int a = grid[i][j] - 'a';
      A[a].emplace_back(P(i, j));
    }
  }
  rep(i, h){
    rep(j, w) dist[i][j] = INF;
  }
  dijkstra(sy, sx);
  if(dist[gy][gx] == INF){
    dist[gy][gx] = -1;
  }
  cout << dist[gy][gx] << endl;
}