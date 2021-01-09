#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PP = pair<P, int>;
typedef long long ll;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<string> grid;
int h, w;
int gy, gx;
vector<vector<bool>> visited;
long double ten[250001];

bool bfs(int x, int y, long double mid){
  visited[x][y] = true;
  queue<PP> que;
  que.push(PP(P(x, y), 0));
  while (!que.empty()){
    PP p = que.front();
    que.pop();
    int c = p.second;
    int cx = p.first.first, cy = p.first.second;
    rep(i, 4){
      int ny = cy + dy[i], nx = cx + dx[i];
      if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
      if(grid[nx][ny] == '#')continue;
      if(grid[nx][ny] == 's')continue;
      if(visited[nx][ny])continue;
      if(grid[nx][ny] == 'g'){
        visited[nx][ny] = true;
        return true;
      }
      int k = (grid[nx][ny] - '0');
      long double tmp = (long double)k * ten[c + 1];
      if(tmp < mid)continue;
      visited[nx][ny] = true;
      que.push(PP(P(nx, ny), c+ 1));
    }
  }
  return visited[gx][gy];
}

void dfs(int x, int y){
  if(visited[x][y])return;
  visited[x][y] = true;
  rep(i, 4){
    int ny = y + dy[i], nx = x + dx[i];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(grid[nx][ny] == '#')continue;
    dfs(nx, ny);
  }
  return;
}



int main() {
  cin >> h >> w;
  grid.resize(h);
  visited.resize(h, vector<bool>(w, false));
  rep(i, h) cin >> grid[i];
  int sx, sy;
  visited.resize(h, vector<bool>(w));
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == 's')sx = i, sy = j;
      if(grid[i][j] == 'g')gx = i, gy = j;
    }
  }
  dfs(sx, sy);
  if(!visited[gx][gy]){
    cout << -1 << endl;
    return 0;
  }
  ten[0] = 1.00L;
  rep(i, 250000){
    ten[i + 1] = ten[i] * 0.99L;
  }
  long double left = 0.00L;
  long double right = 9.01L;
  rep(i, 100){
    long double mid = (left + right) * 0.5L;
    visited.assign(h, vector<bool>(w, false));
    if(bfs(sx, sy, mid))left = mid;
    else right = mid;
  }
  cout << fixed << setprecision(10) << left << endl;
}