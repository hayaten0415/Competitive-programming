#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[6] = {1, 0, -1, 0, -1, 1};
const int dy[6] = {0, 1, 0, -1, 1, 1};
const int INF = (1 << 30);

int main() {
  int n, X, Y;
  cin >> n >> X >> Y;
  X += 205;
  Y += 205;
  vector<vector<int>> dist(410, vector<int>(410, INF));
  vector<string> grid(410, string(410, '.'));
  dist[205][205] = 0;
  rep(i, n){
    int x, y;
    cin >> x >> y;
    x += 205;
    y += 205;
    grid[x][y] = '#';
  }
  queue<P> que;
  que.push(P(205, 205));
  while (!que.empty()){
    P p = que.front();
    que.pop();
    rep(i, 6){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= 410 || ny >= 410)continue;
      if(grid[nx][ny] == '#')continue;
      if(dist[nx][ny] != INF)continue;
      dist[nx][ny] = dist[p.first][p.second] + 1;
      que.push(P(nx, ny));
    }
  }
  if(dist[X][Y] == INF){
    cout << -1 << endl;
  }else{
    cout << dist[X][Y] << endl;
  }
}