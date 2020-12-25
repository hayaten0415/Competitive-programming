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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  queue<P> que;
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == '#'){
        dist[i][j] = 0;
        que.push(P(i, j));
      }
    }
  }
  while (!que.empty()){
    P p = que.front();
    que.pop();
    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
      if(grid[nx][ny] == '#')continue;
      if(dist[nx][ny] != INF)continue;
      dist[nx][ny] = dist[p.first][p.second] + 1;
      que.push(P(nx, ny));
    }
  }
  int ans = 0;
  rep(i, h){
    rep(j, w){
      chmax(ans,dist[i][j]);
    }
  }
  cout << ans << endl;
}