#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i,h){
    cin >> grid[i];
  }
  int white_count = 0;
  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '.') white_count++;
    }
  }
  vector<vector<int>> dist(h, vector<int>(w, INF));
  //vector<vector<int>> prev_x(h, vector<int>(w, -1));
  //vector<vector<int>> prev_y(h, vector<int>(w, -1));
  queue<P> que;
  dist[0][0] = 0;
  que.push({0, 0});
  while(!que.empty()){
    P p = que.front(); que.pop();
    int y = p.first, x = p.second;
    rep(i,4){
      int ny = y + dy[i], nx = x + dx[i];
      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if(grid[ny][nx] == '#') continue;
      if(dist[ny][nx] != INF) continue;
      dist[ny][nx] = dist[y][x] + 1;
      //prev_y[ny][nx] = y;
      //prev_x[ny][nx] = x;
      que.push({ny, nx});
    }
  }
  if(dist[h-1][w-1] == INF){
    cout << -1 << endl;
    return 0;
  }
  cout << white_count - dist[h - 1][w - 1] -1 << endl;
  //経路復元
  //int y = h - 1;
  //int x = w - 1;
  //while(x != -1 && y != -1){
  //  grid[y][x] = 'a';
  //  int px = prev_x[y][x];
  //  int py = prev_y[y][x];
  //  x = px, y = py;
  //}
}