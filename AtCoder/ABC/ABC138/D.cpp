#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

using Graph = vector<vector<int>>;
Graph G;
void dfs(int u, int p, vector<int> &ans){
  if(p != -1) ans[u] += ans[p];
  for(auto v: G[u]){
    if(v == p) continue;
    dfs(v, u, ans);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> ans(n, 0);
  rep(i,q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0, -1, ans);
  rep(i,n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}