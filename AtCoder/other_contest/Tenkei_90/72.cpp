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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int ans = 0;
string grid[16];
int h, w;

void dfs(int x, int y, int prex, int prey, P start, int num, vector<vector<bool>> visited){
  if(prex != -1 && prey != -1){
    num++;
    visited[x][y] = true;
  }
  auto [gx, gy] = start;
  if(prex != -1 && prey != -1 && x == gx && y == gy){
    chmax(ans, num);
    return;
  }
  rep(i, 4){
    int nx = x + dx[i], ny = y + dy[i];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(grid[nx][ny] == '#')continue;
    if(visited[nx][ny])continue;
    dfs(nx, ny, x, y, start, num, visited);
  }
}

int main() {
  cin >> h >> w;
  rep(i, h) cin >> grid[i];
  vector<vector<bool>> visited(h, vector<bool>(w));
  rep(i, h)rep(j, w){
    P start = {i, j};
    dfs(i, j, -1, -1, start, 0, visited);
  }
  if(ans < 3)ans = -1;
  cout << ans << endl;
}