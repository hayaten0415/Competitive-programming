#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using namespace atcoder;

using P = pair<int, int>;
using Graph = vector<vector<P>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
Graph G;
bool non_tree[400000];


int main() {
  int n;
  cin >> n;
  dsu d(n);
  vector<P> self_loop(n);
  vector<int> edge_enable(n);
  G.resize(n);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(a == b){
      self_loop[a].first = 1;
      self_loop[a].second = i;
      non_tree[d.leader(a)] = true;
      edge_enable[i] = 1;
      continue;
    }
    G[a].pb({b, i});
    G[b].pb({a, i});
    if(d.same(a, b)){
      non_tree[d.leader(a)] = true;
    }
    if(non_tree[d.leader(a)] | non_tree[d.leader(b)]){
      d.merge(a, b);
      non_tree[d.leader(a)] = true;
    }
    d.merge(a, b);
  }
  rep(i, n){
    if(d.leader(i) != i)continue;
    if(!non_tree[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  vector<vector<int>> lis = d.groups();
  vector<int> used(n);
  vector<int> ans(n, -1);
  auto root_v = [&](auto &&self, int u, int p, int e, int &start) -> void{
    if(used[u] == 1){
      start = u;
      edge_enable[e] = 1;
      ans[e] = u;
      return;
    }
    used[u] = 1;
    for(auto [v, b] : G[u]){
      if(v ==p)continue;
      self(self, v, u, b, start);
    }
    return;
  };
  auto dfs = [&](auto &&self, int u, int p, int e, vector<int>& res) -> void{
    used[u] = 1;
    if(e != -1 && res[e] == -1){
      res[e] = u;
    }
    for(auto [v, b] : G[u]){
      if(v ==p)continue;
      if(used[v])continue;
      if(edge_enable[b] == 1)continue;
      self(self, v, u, b, res);
    }
    return;
  };
  for(auto s : lis){
    int root = -1;
    for (auto d : s){
      if(self_loop[d].first == 1){
        root = d;
        ans[self_loop[d].second] = d;
      }
    }
    int root_tmp = -1;
    for (auto d : s){
      root_tmp = d;
      break;
    }
    if(root == -1){
      root_v(root_v, root_tmp, -1, -1, root);
    }
    used.assign(n, 0);
    dfs(dfs, root, -1, -1, ans);
  }
  rep(i, n){
    cout << ans[i] + 1 << "\n";
  }
}