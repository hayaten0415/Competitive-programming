#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 100000000000;
// グラフ
using Edge = pair<int, ll>;         // {重み, 行き先}
using Graph = vector<vector<int>>; // グラフ

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> dist(n, INF);
  vector<int> pre(n, -1);
  Graph G(n);
  dist[0] = 0;
  queue<int> que;
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  que.push(0);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist[u] != INF) continue;
      dist[u] = dist[v] + 1;
      pre[u] = v;
      que.push(u);
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i < n; i++){
    cout << pre[i] + 1 << endl;
  }
  return 0;
}