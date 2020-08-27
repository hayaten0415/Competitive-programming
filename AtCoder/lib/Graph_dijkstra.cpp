#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int INF = 1 << 29;

// グラフ
using Edge = pair <int, ll>;  // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ

// 使われうる辺集合
set<pair<int, int>> use;

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

        //経路復元のためのもの
        prev[e.first].clear();
        prev[e.first].push_back(v);
      }else if(dist[e.first] == dist[v] + e.second){
        prev[e.first].push_back(v);
      }
    }
  }
  for (int i = 0; i < (int)G.size(); i++){
    for(auto u : prev[i]){
      use.insert(make_pair(min(u,i), max(u,i)));
    }
  }
  return dist;
}


int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }
}