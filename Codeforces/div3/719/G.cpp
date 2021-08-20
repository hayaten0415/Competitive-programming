#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using ul = unsigned long long;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 61);


void solve() {
  int h, w;
  ll c;
  cin >> h >> w >> c;
  vector<vector<ll>> grid(h, vector<ll>(w));
  rep(i, h) rep(j, w){
    cin >> grid[i][j];
  }
  auto bfs = [&](int sx, int sy) -> vector<vector<ll>> {
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[sx][sy] = 0;
    queue<P> que;
    que.push(P(sx, sy));
    while (!que.empty()){
      P p = que.front();
      que.pop();
      if(grid[p.fi][p.se] == -1)continue;
      rep(i, 4){
        int nx = p.first + dx[i], ny = p.second + dy[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
        if(grid[nx][ny] == -1)continue;
        if(dist[nx][ny] != INF)continue;
        dist[nx][ny] = dist[p.first][p.second] + 1;
        que.push(P(nx, ny));
      }
    }
    return dist;
  };
  auto dist1 = bfs(0, 0);
  auto dist2 = bfs(h - 1, w - 1);
  ll ans;
  if(dist1[h-1][w-1] == INF){
    ans = INF;
  }else{
    ans = dist1[h - 1][w - 1] * c;
  }
  ll left = INF, right = INF;
  rep(i, h)rep(j, w){
    if(grid[i][j] > 0){
      if(dist1[i][j] != INF){
        chmin(left, grid[i][j] + c * dist1[i][j]);
      }
      if(dist2[i][j] != INF){
        chmin(right, grid[i][j] + c * dist2[i][j]);
      }
    }
  }
  chmin(ans, left + right);
  if(ans == INF)ans = -1;
  cout << ans << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}