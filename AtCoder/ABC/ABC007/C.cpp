#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int dist[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int r, c;
  cin >> r >> c;
  //スタート座標
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >>gx;
  sy--; sx--; gy--;gx--;
  vector<string> maze(r);
  rep(i,r){
    cin >> maze[i];
  }
  rep(i, 51) rep(j, 51) dist[i][j] = -1;
  queue<P> que;
  que.push(make_pair(sy, sx));
  dist[sy][sx] = 0;
  while (!que.empty()){
    P p = que.front(); que.pop();
    for (int i = 0; i < 4; i++){
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if(0 <= nx && nx < c && 0 <= ny && ny < r && maze[ny][nx] != '#' && dist[ny][nx] == -1){
        que.push(make_pair(ny, nx));
        dist[ny][nx] = dist[p.first][p.second] + 1;
      }
    }
  }
  cout << dist[gy][gx] << endl;
}