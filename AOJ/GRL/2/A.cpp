#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
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

ll kruskal(){
  sort(ALL(es), comp);
  UnionFind uf(n);
  ll res = 0;
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
    cin >> a >> b >> c;
    es[i] = Edge{a, b, c};
  }
  cout << kruskal() << endl;
}