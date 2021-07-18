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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);


struct Edge{
  int to;
  ll c, d;
};

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
    for(Edge e : G[v]) {
      ll d = dist[v];
      if(d < sqrtl(e.d))d = sqrtl(e.d);
      if(dist[e.to] > d + e.c + (e.d / (d + 1))){
        dist[e.to] = d + e.c + (e.d / (d + 1));
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }
  return dist;
}


int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i,m){
    int a, b;
    ll c, d;
    cin >> a >> b >> c>> d;
    --a; --b;
    G[a].eb(Edge({b,c, d}));
    G[b].eb(Edge({a,c, d}));
  }
  vector<ll> dist = dijkstra(G, 0);
  ll ans = dist[n - 1];
  if(ans == INF)ans = -1;
  cout << ans << endl;
}