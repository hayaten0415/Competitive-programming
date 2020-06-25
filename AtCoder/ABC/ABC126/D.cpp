#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 100000000000;
// グラフ
using Edge = pair<int, int>;         // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ

vector<int> ans;

void dfs(int v, int p, int c, Graph &G){
  ans[v] = c;
  for(auto e : G[v]){
    if(e.first == p) continue;
    if(e.second % 2 == 0)dfs(e.first, v, c, G);
    else dfs(e.first, v, 1-c, G);
  }
}

int main(){
  int n;
  cin >> n;
  Graph G(n);
  rep(i,n-1){
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    G[u].push_back(Edge(v,w));
    G[v].push_back(Edge(u,w));
  }
  ans.assign(n, 0);
  dfs(0, -1, 1, G);
  rep(i, n){
    cout << ans[i] << endl;
  }
}