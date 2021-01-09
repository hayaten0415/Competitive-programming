#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PP = pair<long long, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<string> grid;
vector<vector<ll>> dist;
const ll INF = 1000000000;
int H, W;
int gy, gx;
vector<vector<P>> pre;
vector<P> Route;

//二次元グリッドグラフでのダイクストラ法
void dijkstra(int sy, int sx){
  dist = vector<vector<ll>>(H, vector<ll>(W, INF));
  pre = vector<vector<P>>(H, vector<P>(W)); // pre[i][j] := (i, j) の前に通ったグリッド
  dist[sy][sx] = 0;
  pre[sy][sx] = {-1, -1};
  priority_queue<PP, vector<PP>, greater<PP>> que;
  que.push(PP(0, P(sy, sx)));
  while(!que.empty()) {
    PP p = que.top();
    que.pop();
    int c = p.first;
    int cy = p.second.first, cx = p.second.second;
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny < 0 || H <= ny || nx < 0 || W <= nx)continue;
      if(grid[ny][nx] == '#')continue;
      ll tmp = 10;
      if(grid[ny][nx] != 'g' &&  grid[ny][nx] != 's'){
        ll k = grid[ny][nx] - '0';
        tmp -= k;
      }else {
        tmp = 0;
      }
      if(dist[ny][nx] < dist[cy][cx] + tmp)continue;
      dist[ny][nx] = dist[cy][cx] + tmp;
      que.push(PP(dist[ny][nx], P(ny, nx)));
      pre[ny][nx] = {cy, cx};
    }
  }
  //復元パート
  P p = P(gx, gy);
  //経路復元パート
  while (p.first != -1 && p.second != -1){
    Route.emplace_back(p);
    p = pre[p.first][p.second];
  }
  reverse(ALL(Route));
  rep(i, Route.size()){
    cout << Route[i].first << " " << Route[i].second << endl;
  }

}

int main() {
  cin >> H >> W;
  grid.resize(H);
  rep(i, H) cin >> grid[i];
  int sy, sx;
  rep(i, H){
    rep(j, W){
      if(grid[i][j] == 's')sy = i, sx = j;
      if(grid[i][j] == 'g')gy = i, gx = j;
    }
  }
  dijkstra(sy, sx);
}