#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder
using namespace atcoder;
using Graph = vector<vector<int>>;
vector<int> loop;
vector<ll> path_cn;
vector<int> visited_cn;
Graph G;

void dfs(int u, int p){
  if(p != -1 && loop[p] == 0){
    if(path_cn[p] > 1){
      path_cn[u] = 2;
    }else{
      path_cn[u] += path_cn[p];
    }
  }
  visited_cn[u]++;
  if(p != -1 && loop[p] == 1){
    loop[u] = 1;
  }
  for(auto v : G[u]){
    if(v == p)continue;
    if((visited_cn[v] > 0) && (loop[v] == 1))continue;
    if(visited_cn[v] > 1 && (loop[u] != 1))continue;
    dfs(v, u);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  loop.assign(n, 0);
  path_cn.assign(n, 0);
  scc_graph g(n);
  G.resize(n);
  visited_cn.assign(n, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
    if(a == b){
      loop[a] = 1;
      continue;
    }
    G[a].pb(b);
  }
  path_cn[0] = 1;
  auto scc = g.scc();
  for(auto v : scc){
    if(v.size() == 1)continue;
    for(int x : v){
      loop[x] = true;
    }
  }
  dfs(0, -1);
  vector<int> ans(n);
  rep(i, n){
    if(visited_cn[i] == 0){
      ans[i] = 0;
      continue;
    }
    if(loop[i]== 1){
      ans[i] = -1;
      continue;
    }
    if(path_cn[i] == 1){
      ans[i] = 1;
      continue;
    }
    if(path_cn[i] > 1){
      ans[i] = 2;
      continue;
    }
  }
  rep(i, n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
  G.clear();
  visited_cn.clear();
  loop.clear();
  path_cn.clear();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}