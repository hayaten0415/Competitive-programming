#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using PP = pair<long long, P>;
typedef long long ll;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<string> grid;
vector<vector<ll>> dist;
const ll INF = 10000000000000;
int H, W;
int sy, sx, gy, gx;
ll T;
ll pl;

//二次元グリッドグラフでのダイクストラ法
bool dijkstra(int y, int x){
  dist = vector<vector<ll>>(H, vector<ll>(W, INF));
  dist[y][x] = 0;
  priority_queue<PP, vector<PP>, greater<PP>> que;
  que.push(PP(0, P(y, x)));
  while(!que.empty()) {
    PP p = que.top();
    que.pop();
    ll c = p.first;
    int cy = p.second.first, cx = p.second.second;
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i], nx = cx + dx[i];
      ll tmp;
      if (ny < 0 || H <= ny || nx < 0 || W <= nx)continue;
      if(grid[ny][nx] == '#'){
        tmp = pl;
      }else{
        tmp = 1;
      }
      if(dist[ny][nx] <= dist[cy][cx] + tmp)continue;
      dist[ny][nx] = dist[cy][cx] + tmp;
      que.push(PP(dist[ny][nx], P(ny, nx)));
    }
  }
  if(dist[gy][gx] <= T)return true;
  else return false;
}

int main() {
  cin >> H >> W >> T;
  grid.resize(H);
  rep(i, H) cin >> grid[i];
  rep(i, H){
    rep(j, W){
      if(grid[i][j] == 'S'){
        sy = i; sx = j;
      }
      if (grid[i][j] == 'G'){
        gy = i; gx = j;
      }
    }
  }
  ll left = 0;
  ll right = T + 1;
  while(right -left > 1){
    ll mid = (left + right) / 2;
    pl = mid;
    if(dijkstra(sy, sx)){
      left = mid;
    }else {
      right = mid;
    }
  }
  cout << left << endl;
}