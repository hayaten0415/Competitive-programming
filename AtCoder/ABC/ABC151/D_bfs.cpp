#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(const vector<string> &v, int x, int y) {
  int h = v.size(), w = v[0].size();
  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<P> que;
  int res = 0;
  que.push(make_pair(x, y));
  dist[x][y] = 0;
  while (!que.empty()){
    P p = que.front(); que.pop();
    res = max(res, dist[p.first][p.second]);
    for (int i = 0; i < 4; i++){
      int ny = p.second + dy[i], nx = p.first + dx[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w && v[nx][ny] != '#' && dist[nx][ny] == -1){
        dist[nx][ny] = dist[p.first][p.second] + 1;
        que.push(make_pair(nx, ny));
      }
    }
  }
  return res;
}

int main() {
  int H, W;
  cin >> H >> W;
  int res = 0;
  vector<string> v(H);
  rep(i, H) cin >> v[i];
  rep(x, H){
    rep(y, W){
      if(v[x][y] == '#') continue;
      res = max(res, bfs(v, x, y));
    }
  }
  cout << res << endl;
}