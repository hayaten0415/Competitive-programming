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
const int INF = 1 << 29;

ll dists[1000][1000];

// グラフ
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
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  s--, t--;
  Graph G(n);
  rep(i,m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }
  vector<ll> dist1 = dijkstra(G, s);
  vector<ll> dist2 = dijkstra(G, t);
  rep(i, n){
    if(dist1[i] == dist2[i] && dist1[i] != INF){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}