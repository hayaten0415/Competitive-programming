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
  vector<string> grid(h);
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
      for (int j = 1; j <= k; j++){
        int nx = p.first + j * dx[i], ny = p.second + j * dy[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w)break;
        if(grid[nx][ny] == '@')break;
        if(dist[nx][ny] != INF && dist[p.first][p.second] >= dist[nx][ny])break;
        if(dist[nx][ny] != INF)continue;
        dist[nx][ny] = dist[p.first][p.second] + 1;
        que.push(P(nx, ny));
      }
    }
  }
  if(dist[gx][gy] == INF){
    cout << -1 << endl;
  }else{
    cout << dist[gx][gy] << endl;
  }
}
