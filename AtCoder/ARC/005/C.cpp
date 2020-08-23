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
  int sy, sx, gy, gx;
  string grid[h];
  int dist[h][w];
  rep(i, h) cin >> grid[i];
  rep(i, h){
    rep(j, w){
      dist[i][j] = INF;
      if(grid[i][j] == 's'){
        sy = i, sx = j;
      }
      if(grid[i][j] == 'g'){
        gy = i, gx = j;
      }
    }
  }
  dist[sy][sx] = 0;
  deque<P> que;
  que.push_front(P(sy, sx));
  while (!que.empty()){
    P p = que.front();
    que.pop_front();
    int y = p.first, x = p.second;
    rep(i, 4){
      int ny = y + dy[i], nx = x + dx[i];
      int plus = 0;
      if(ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
      if(grid[ny][nx] == '#')plus = 1;
      if(dist[ny][nx] <= dist[y][x] + plus)continue;
      dist[ny][nx] = dist[y][x] + plus;
      if(plus == 1){
        que.push_back(P(ny, nx));
      }else{
        que.push_front(P(ny, nx));
      }
    }
  }
  if(dist[gy][gx] <= 2){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }
}