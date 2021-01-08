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
int dist[2010][2010];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int sx = h - 1, sy = w;
  rep(i, h) rep(j, w) dist[i][j] = INF;
  dist[sx][sy] = 0;
  deque<P> que;
  que.push_front({sx, sy});
  while (!que.empty()){
    P p = que.front();
    que.pop_front();
    auto [x, y] = p;
    int nx = x, ny = y;
    nx--;
    if(nx >= 0 && nx < h && ny >= 0 && ny < w && dist[nx][ny] > dist[x][y]){
      if(grid[nx][ny] == 'S'){
        dist[nx][ny] = dist[x][y];
        que.push_front({nx, ny});
      }else{
        dist[nx][ny] = dist[x][y] + 1;
        //grid[nx][ny] = 'S';
        que.push_back({nx, ny});
      }
    }
    nx++;
    ny--;
    if(nx >= 0 && nx < h && ny >= 0 && ny < w && dist[nx][ny] > dist[x][y]){
      if(grid[nx][ny] == 'E'){
        dist[nx][ny] = dist[x][y];
        que.push_front({nx, ny});
      }else{
        dist[nx][ny] = dist[x][y] + 1;
        //grid[nx][ny] = 'E';
        que.push_back({nx, ny});
      }
    }
  }
  cout << dist[0][0] << endl;
}