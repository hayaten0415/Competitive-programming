#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, P>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max();
Graph G;

struct UnionFindUndo {
  vector< int > data;
  stack< pair< int, int > > history;

  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }

  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }

  void snapshot() {
    while(history.size()) history.pop();
  }

  void rollback() {
    while(history.size()) undo();
  }
};



int dep[200002];
int in[200002];
int out[200002];
int tree_size[200002];
vector<int> ls[200002];


//通った頂点を並べたもの
vector<int> EularTour_V;
//通った辺を並べたもの
vector<int> EularTour_E;
int k;
void dfs(int v,int p, int d) {
  EularTour_V.pb(v);
  EularTour_E.pb(v);
  in[v] = k;
  k++;
  dep[v] = d;
  tree_size[v] = 1;
  for (int u : G[v]){
    if(u ==p)continue;
    dfs(u, v, d + 1);
    EularTour_V.pb(v);
    tree_size[v] += tree_size[u];
  }
  out[v] = k;
  EularTour_E.pb(-v);
  k++;
}

int main() {
  int n;
  cin >> n;
  dsu d(n);
  G.resize(n);
  vector<PL> edge(n - 1);
  rep(i, n-1){
    int a, b;
    ll w;
    cin >> a >> b >> w;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
    edge[i].second.first = a;
    edge[i].second.second = b;
    edge[i].first = w;
  }
  sort(ALL(edge));
  UnionFindUndo uf(n);
  dfs(0, -1, 0);
  rep(i, n-1){
    uf.unite(edge[i].second.first, edge[i].second.second);
  }
  ll ans = 0;
  rrep(i, n-1){
    uf.undo();
    int a = edge[i].second.first;
    int b = edge[i].second.second;
    ans += (ll)uf.size(a) * (ll)uf.size(b) * edge[i].first;
  }
  cout << ans << endl;
}