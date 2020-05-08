#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

// グラフ
using Edge = pair<int, ll>;         // {行き先,重み}
using Graph = vector<vector<Edge>>; // グラフ

vector<ll> dist;
Graph G;
void dfs(int v, int p, ll d){
  dist[v] = d;
  for(auto e : G[v]){
    if(e.first == p) continue;
    dfs(e.first, v, d + e.second);
  }
}

int main() {
  int n;
  cin >> n;
  dist.resize(n);
  G.resize(n);
  rep(i, n-1){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
  }
  int q, k;
  cin >> q >> k;
  k--;
  dfs(k, -1, 0);
  rep(i,q){
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << dist[x] + dist[y] << endl;
  }
}