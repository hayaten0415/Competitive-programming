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
int h, w;
int gy, gx;
int k;
int ans;
vector<P> Route;
bool ok = false;

void dfs(int sy, int sx, int c, int py, int px, vector<string> &grid, vector<vector<bool>> visited, vector<vector<P>> pre){
  visited[sy][sx] = true;
  pre[sy][sx] = {py, px};
  chmax(ans,c);
  if(ans == k-1){
    P p = P(sy, sx);
    while (Route.size() < k){
      Route.emplace_back(p);
      p = pre[p.first][p.second];
    }
    ok = true;
    return;
  }
  rep(i, 4) {
    int ny = sy + dy[i], nx = sx + dx[i];
    if(ny >= h || nx >= w || ny < 0 || nx < 0)continue;
    if(visited[ny][nx])continue;
    if(grid[ny][nx] == '.')continue;
    dfs(ny, nx, c + 1, sy, sx, grid, visited, pre);
  }
  return;
}

int main() {
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vector<vector<P>> pre(h, vector<P>(w, {-1, -1}));
  vector<vector<int>> dist(h, vector<int>(w));
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  vector<P> snake;
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == '#')snake.emplace_back(P(i, j));
    }
  }
  k = snake.size();
  rep(s, k){
    vector<vector<bool>> visited_tmp = visited;
    vector<vector<P>> pre_tmp = pre;
    ans = 0;
    dfs(snake[s].first, snake[s].second, 0, -1, -1, grid, visited_tmp, pre_tmp);
    if(ok){
      break;
    }
  }
  reverse(ALL(Route));
  cout << k << endl;
  rep(i, k){
    cout << Route[i].first + 1 << " " << Route[i].second + 1 << endl;
  }
}