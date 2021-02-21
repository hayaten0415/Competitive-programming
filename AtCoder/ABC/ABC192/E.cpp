#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const ll INF = 1LL << 60;

// グラフ
struct Edge {
  int to;
  ll cost, k;
};
using Graph = vector<vector<Edge>>; // グラフ


vector<ll> dijkstra(const Graph &G, int s){
  vector<ll> dist((int)G.size(), INF);
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  que.push(make_pair(0, s));
  while(!que.empty()) {
    auto cur = que.top(); que.pop();
    ll cur_dist = cur.first;
    int v = cur.second;
    if(cur_dist > dist[v]) continue; //枝狩り
    for(auto e : G[v]) {
      if(dist[v] % e.k != 0){
        if(dist[e.to] > dist[v] + e.cost + (e.k - (dist[v] % e.k))){
          dist[e.to] = dist[v] + e.cost + (e.k - (dist[v] % e.k));
          que.push(make_pair(dist[e.to], e.to));
        }
      }else{
        if(dist[e.to] > dist[v] + e.cost){
          dist[e.to] = dist[v] + e.cost;
          que.push(make_pair(dist[e.to], e.to));
        }
      }
    }
  }
  return dist;
}


int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  Graph G(n);
  rep(i,m){
    int a, b;
    ll t, k;
    cin >> a >> b >> t >> k;
    --a; --b;
    Edge e, f;
    e.to = b;
    e.cost = t;
    e.k = k;
    f.to = a;
    f.cost = t;
    f.k = k;
    G[a].push_back(e);
    G[b].push_back(f);
  }
  vector<ll> dist = dijkstra(G, x);
  cout << (dist[y] == INF ? -1 : dist[y]) << endl;
}