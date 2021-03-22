#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

using Edge = pair<int, ll>;         // {行き先, 重み}
using Graph = vector<vector<Edge>>; // グラフ



template <typename T>
pair<T, int> dfs(const Graph &G, int u, int par) {  // 最遠点間距離と最遠点を求める
  pair<T, int> ret = make_pair((T)0, u);
  for (auto e : G[u]) {
      if (e.first == par) continue;
      auto next = dfs<T>(G, e.first, u);
      next.first += e.second;
      ret = max(ret, next);
  }
  return ret;
}

pair<int, int> tree_diamiter(const Graph &G) {
  pair<ll, int> p = dfs<ll>(G, 0, -1);
  pair<ll, int> q = dfs<ll>(G, p.second, -1);
  return {p.second, q.second};
}

int main() {
  int n;
  cin >> n;
  Graph G(n);
  rep(i, n-1){
    int s, t;
    cin >> s >> t;
    s--, t--;
    G[s].push_back({t, 1});
    G[t].push_back({s, 1});
  }
  pair<int, int> ans = tree_diamiter(G);
  cout << ans.first + 1 << " " << ans.second + 1<< endl;
}