#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 100000000000;
const int MOD = 1000000007;

// グラフ
using Edge = pair<int, ll>;         // {重み, 行き先}
using Graph = vector<vector<int>>; // グラフ

int main() {
  int n, m, a, b;
  cin >> n >> a >> b >> m;
  a--; b--;
  vector<ll> dist(n, INF);
  vector<ll> cnt(n, 0);
  Graph G(n);
  dist[a] = 0;
  cnt[a] = 1;
  queue<int> que;
  rep(i,m){
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  que.push(a);
  while (!que.empty()){
    int u = que.front();
    que.pop();
    if(u == b) break;
    for(int v: G[u]){
      if(dist[v] == INF){
        dist[v] = dist[u] + 1;
        cnt[v] += cnt[u];
        cnt[v] %= MOD;
        que.push(v);
      }else if(dist[v] == dist[u] +1){
        cnt[v] += cnt[u];
        cnt[v] %= MOD;
      }
    }
  }
  cout << cnt[b] % MOD << endl;
}