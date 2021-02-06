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
const ll INF = 1LL << 59;

// グラフ
using Edge = pair <int, ll>;  // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ
ll dist[100005];
void dijkstra(const Graph &G, int s){
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
}


int main() {
  int n, m;
  ll ab, bc, ca;
  string f;
  cin >> n >> m;
  cin >> ab >> ca >> bc;
  cin >> f;
  Graph G(n+ 3);
  rep(i, n+3) dist[i] = INF;
  rep(i, n){
    if(f[i] == 'A'){
      G[n].push_back(Edge(i, 0));
      G[i].push_back(Edge(n + 1, ab));
      G[i].push_back(Edge(n + 2, ca));
    }
    if(f[i] == 'B'){
      G[n+1].push_back(Edge(i, 0));
      G[i].push_back(Edge(n, ab));
      G[i].push_back(Edge(n + 2, bc));
    }
    if(f[i] == 'C'){
      G[n + 2].push_back(Edge(i, 0));
      G[i].push_back(Edge(n, ca));
      G[i].push_back(Edge(n + 1, bc));
    }
  }
  rep(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }
  dijkstra(G, 0);
  cout << dist[n-1] << endl;
}