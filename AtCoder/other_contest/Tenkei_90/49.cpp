#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

struct UnionFind {
  vector<int> par; //par[i]:iの親の番号

  //最初は全てが根であるとする。-1のときに根である。
  UnionFind(int N) : par(N, -1){}

  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
  int root(int x) {
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  // データxが根かどうか
  bool cond_root(int x){
    if(par[x] < 0) return true;
    else return false;
  }
  //xとyが同じ集合に属するか
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) {
    return -par[root(x)];
  }
};

int n, m;

struct Edge {
  int from, to;
  ll cost;
};

bool comp(const Edge& e1, const Edge& e2){
  return e1.cost < e2.cost;
}
vector<Edge> es;
UnionFind uf((int)1e5 + 1);

//無向グラフの想定
ll kruskal(){
  sort(ALL(es), comp);
  ll res = 0;
  UnionFind uf(n + 1);
  rep(i, m){
    Edge e = es[i];
    if(uf.issame(e.to, e.from))continue;
    uf.merge(e.to, e.from);
    res += e.cost;
  }
  return res;
}

int main() {
  cin >> n >> m;
  es.resize(m);
  rep(i, m){
    int a, b;
    ll c;
    cin >> c >> a >> b;
    a--;
    es[i] = Edge{a, b, c};
  }
  sort(ALL(es), comp);
  ll res = 0;
  UnionFind uf(n + 1);
  rep(i, m){
    Edge e = es[i];
    if(uf.issame(e.to, e.from))continue;
    uf.merge(e.to, e.from);
    res += e.cost;
  }
  if(uf.size(0) == n + 1){
    cout << res << endl;
  }else{
    cout << -1 << endl;
  }
}