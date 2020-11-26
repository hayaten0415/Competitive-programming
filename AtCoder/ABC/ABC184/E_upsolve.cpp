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



int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vector<vector<P>> warps(256);
  vector dist(h, vector(w, INF));
  queue<P> que;
  rep(i, h)rep(j,w){
    if(grid[i][j] == 'S'){
      que.push(P(i, j));
      dist[i][j] = 0;
    }
  }
  rep(i, h)rep(j, w)warps[grid[i][j]].emplace_back(i, j);
  while(!que.empty()) {
    auto [cy, cx] = que.front();
    que.pop();
    if (grid[cy][cx] == 'G') {
      cout << dist[cy][cx] << endl;
      return 0;
    }
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny < 0 || h <= ny || nx < 0 || w <= nx)continue;
      if(grid[ny][nx] == '#')continue;
      if(dist[ny][nx] != INF)continue;
      dist[ny][nx] = dist[cy][cx] + 1;
      que.push(P(ny, nx));
    }
    if(islower(grid[cy][cx])){
      for(P p :warps[grid[cy][cx]]){
        int ny = p.first, nx = p.second;
        if(dist[ny][nx] != INF)continue;
        dist[ny][nx] = dist[cy][cx] + 1;
        que.push(P(ny, nx));
      }
      warps[grid[cy][cx]].clear();
    }
  }
  cout << -1 << endl;
  return 0;
}