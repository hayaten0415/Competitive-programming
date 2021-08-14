#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PP = pair<P, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int INF = (1 << 30);

int dist[2000][2000][4];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--, sy--, gx--, gy--;
  rep(i, h) cin >> grid[i];
  rep(i, h)rep(j, w)rep(s, 4)dist[i][j][s] = INF;
  rep(i, 4) dist[sx][sy][i] = 0;
  deque<PP> que;
  rep(i, 4)que.push_back(PP(P(sx, sy), i));
  while (!que.empty()){
    PP a = que.front();
    int c = a.second;
    P p = a.first;
    que.pop_front();
    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
      if(grid[nx][ny] == '#')continue;
      if(i != c){
        if(dist[nx][ny][i] > dist[p.first][p.second][c] + 1){
          dist[nx][ny][i] = dist[p.first][p.second][c] + 1;
          que.push_back(PP(P(nx, ny), i));
        }
      }else{
        if(dist[nx][ny][i] > dist[p.first][p.second][c]){
          dist[nx][ny][i] = dist[p.first][p.second][c];
          que.push_front(PP(P(nx, ny), i));
        }
      }
    }
  }
  cout << min({dist[gx][gy][0], dist[gx][gy][1], dist[gx][gy][2], dist[gx][gy][3]}) << endl;
}