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

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  //pre[x][y] = grid(x, y)の前のgrid;
  vector<vector<P>> pre(h, vector<P>(w, {-1, -1}));
  vector<string> grid(h);
  //経路復元用
  vector<P> Route;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--, sy--, gx--, gy--;
  rep(i, h) cin >> grid[i];
  dist[sx][sy] = 0;
  queue<P> que;
  que.push(P(sx, sy));
  while (!que.empty()){
    P p = que.front();
    que.pop();
    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
      if(grid[nx][ny] == '@')continue;
      if(dist[nx][ny] != INF)continue;
      dist[nx][ny] = dist[p.first][p.second] + 1;
      pre[nx][ny] = {p.first, p.second};
      que.push(P(nx, ny));
    }
  }
  if(dist[gx][gy] == INF){
    cout << -1 << endl;
  }
  P p = P(gx, gy);
  //経路復元パート
  while (p.first != -1 && p.second != -1){
    Route.emplace_back(p);
    p = pre[p.first][p.second];
  }
  reverse(ALL(Route));
  rep(i, Route.size()){
    cout << Route[i].first << " " << Route[i].second << endl;
  }
}