#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
// グラフ
using Edge = pair<int, ll>;         // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 60);
ll dist2[3000][3000];

vector<ll> dijkstra(const Graph &G, int s){
  vector<ll> dist((int)G.size(), INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  que.push(make_pair(0, s));
  while(!que.empty()) {
    auto cur = que.top(); que.pop();
    ll cur_dist = cur.first;
    int v = cur.second;
    if(cur_dist > dist[v]) continue; //枝狩り
    for(auto e : G[v]) {
      if(dist[e.first] > cur_dist + e.second){
        dist[e.first] = cur_dist + e.second;
        que.push(make_pair(dist[e.first], e.first));
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
    ll c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b,c));
  }
  rep(i, n)rep(j, n) dist2[i][j] = INF;
  rep(i, n){
    vector<ll> dist = dijkstra(G, i);
    rep(j, n) chmin(dist2[i][j], dist[j]);
  }
  rep(i, n){
    ll ans = INF;
    rep(j, n){
      if(j == i){
        chmin(ans, dist2[i][j]);
      }else{
        chmin(ans, dist2[i][j] + dist2[j][i]);
      }
    }
    if(ans == INF){
      cout << -1 << endl;
    }else{
      cout << ans << endl;
    }
  }
}