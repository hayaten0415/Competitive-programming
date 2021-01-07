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
const int INF = (1 << 30);

int dist[2001][2001][2];

int main() {
  int h, w;
  cin >> h >> w;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--, sy--, gx--, gy--;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  rep(i, h) rep(j, w) rep(k, 2) dist[i][j][k] = INF;
  dist[sx][sy][0] = dist[sx][sy][1] = 0;
  queue<pair<P, int>> que;
  que.push({{sx, sy}, 0});
  que.push({{sx, sy}, 1});
  while (!que.empty()){
    auto p = que.front();
    que.pop();
    auto [nx, ny] = p.first;
    if(!p.second){
      nx++;
      if(nx < h && grid[nx][ny] != '#' && dist[nx][ny][1]== INF){
        dist[nx][ny][1] = dist[p.first.first][p.first.second][0] + 1;
        que.push({{nx, ny}, 1});
      }
      nx-= 2;
      if(nx >= 0 && grid[nx][ny] != '#' && dist[nx][ny][1]== INF){;
        dist[nx][ny][1] = dist[p.first.first][p.first.second][0] + 1;
        que.push({{nx, ny}, 1});
      }
    }else{
      ny++;
      if(ny < w && grid[nx][ny] != '#' && dist[nx][ny][0]== INF){
        dist[nx][ny][0] = dist[p.first.first][p.first.second][1] + 1;
        que.push({{nx, ny}, 0});
      }
      ny -= 2;
      if(ny >= 0 && grid[nx][ny] != '#' && dist[nx][ny][0]== INF){
        dist[nx][ny][0] = dist[p.first.first][p.first.second][1] + 1;
        que.push({{nx, ny}, 0});
      }
    }
  }
  int ans = min(dist[gx][gy][0], dist[gx][gy][1]);
  if(ans == INF)ans = -1;
  cout << ans << endl;
}