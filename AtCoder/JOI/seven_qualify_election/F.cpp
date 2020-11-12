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
vector<ll> ans;

// グラフ
using Edge = pair <int, ll>;  // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ

vector<ll> dijkstra(Graph &G, int s){
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
      if(dist[e.first] > dist[v] + e.second){
        dist[e.first] = dist[v] + e.second;
        que.push(make_pair(dist[e.first], e.first));
      }
    }
  }
  return dist;
}


int main() {
  int n, k;
  cin >> n >> k;
  Graph G(n);
  rep(i,k){
    int s;
    cin >> s;
    if(s == 1){
      int a, b;
      ll c;
      cin >> a >> b >> c;
      --a; --b;
      G[a].push_back(Edge(b,c));
      G[b].push_back(Edge(a,c));
    }else{
      int a, b;
      cin >> a >> b;
      a--, b--;
      vector<ll> dist = dijkstra(G, a);
      if(dist[b] == INF)dist[b] = -1;
      ans.emplace_back(dist[b]);
    }
  }
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
}