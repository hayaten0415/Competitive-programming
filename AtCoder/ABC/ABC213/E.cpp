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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int INF = (1 <<20);

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  dist[0][0] = 0;
  deque<P> que;
  que.push_front(P(0, 0));
  while (!que.empty()){
    P p = que.front();
    que.pop_front();
    auto [x, y] = p;
    rep(i, 4){
      int nx = x + dx[i], ny = y + dy[i];
      int plus = 0;
      if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
      if(grid[nx][ny] == '.'){
        if(dist[nx][ny] <= dist[x][y])continue;
        dist[nx][ny] = dist[x][y];
        que.push_front(P(nx, ny));
      }
    } 
    for(int sx = x - 2; sx < x + 3; sx++)for(int sy = y - 2; sy < y + 3; sy++){
      if(abs(y -sy) + abs(x - sx) == 4)continue;
      if(sx < 0 || sy < 0 || sx >= h || sy >= w)continue;
      if(dist[sx][sy] <= dist[x][y] + 1)continue;
      dist[sx][sy] = dist[x][y] + 1;
      que.push_back(P(sx, sy));
    }
  }
  cout << dist[h - 1][w - 1] << endl;
}