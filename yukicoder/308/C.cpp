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
using PP = pair<long long, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<62);

using Edge = pair <int, ll>;  // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ


vector<ll> dijkstra(const Graph &G, int s){
  vector<ll> dist((int)G.size(), INF);
  vector<vector<int>> prev((int)G.size()); // prev[v] := v から復元できる辺たち
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  que.push(make_pair(0, s));
  while(!que.empty()) {
    auto cur = que.top(); que.pop();
    ll cur_dist = cur.first;
    int v = cur.second;
    if(cur_dist > dist[v]) continue; //枝狩り
    for(auto e : G[v]) {
      if(dist[e.first] > dist[v] + e.second){
        dist[e.first] = dist[v] + e.second;
        que.push(make_pair(dist[e.first], e.first));
      }
    }
  }
  return dist;
}


int main() {
  int h, w;
  cin >> h >> w;
  Graph G(h * w);
  ll u, d, r, l, k, p;
  cin >> u >> d >> r >> l >> k >> p;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--, sy--, gx--, gy--;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  rep(i, h)rep(j, w){
    int start = i * w + j;
    int right = start + 1;
    int under = start + w;
    ll add2 = 0;
    if(grid[i][j] == '#')continue;
    if(j < w-1 && grid[i][j+1] != '#'){
      ll add1 = 0;
      ll add2 = 0;
      if(grid[i][j] == '@')add1 = p;
      if(grid[i][j+1] == '@')add2 = p;
      G[start].pb({right, r + add2});
      G[right].pb({start, add1 + l});
    }
    if(i < h-1 && grid[i+1][j] != '#'){
      ll add1 = 0;
      ll add2 = 0;
      if(grid[i][j] == '@')add1 = p;
      if(grid[i+1][j] == '@')add2 = p;
      G[start].pb({under, d + add2});
      G[under].pb({start, add1 + u});
    }
  }
  vector<ll> dist = dijkstra(G, sx * w + sy);
  if(dist[gx * w + gy] <= k){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}