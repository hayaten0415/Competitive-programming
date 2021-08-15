#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
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
template <typename T>
const auto INF = numeric_limits<T>::max();

ll op(ll a, ll b) {
  return (a ^ b);
}
ll e() {
  return (ll)(0);
}

int parent[21][200002];
int dep[200002];
int in[200002];
int out[200002];
int tree_size[200002];
vector<int> ls[200002];
int k;
Graph G;


//通った頂点を並べたもの
vector<int> EularTour_V;
//通った辺を並べたもの
vector<int> EularTour_E;

void dfs(int v,int p, int d) {
  EularTour_V.pb(v);
  EularTour_E.pb(v);
  parent[0][v] = p;
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

void init(int N){
  //parentを初期化する
  rep(i,20){
    rep(j, N){
      if(parent[i][j] < 0)parent[i + 1][j] = -1;
      else parent[i+1][j] = parent[i][parent[i][j]];
    }
  }
}


//uとvのLCAを求める
int lca(int u, int v){
  // uとvの深さが同じになるまで親を巡る
  if(dep[u] > dep[v])swap(u, v);
  for(int k = 0; k < 21; k++){
    if((dep[v] - dep[u]) >> k & 1){
      v = parent[k][v];
    }
  }
  if(u == v)return u;
  //二分探索でLCAを求める
  for(int k = 20; k >= 0; k--){
    if(parent[k][u] != parent[k][v]){
        u = parent[k][u];
        v = parent[k][v];
    }
  }
  return parent[0][u];
}


//頂点iの部分木クエリは半開区間[in[i], out[i])となる。
//in[i]のみに値を入れる,out[i]には単位元を入れるとセグ木が正しく動く(1点更新のみ)
//1点更新のセグ木のみverify

// verify https://yukicoder.me/problems/no/1637
// verify https://yukicoder.me/problems/no/1641
// verify https://atcoder.jp/contests/abc202/tasks/abc202_e
// verify https://atcoder.jp/contests/abc201/tasks/abc201_e
// verify https://atcoder.jp/contests/abc209/tasks/abc209_d

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> C(n);
  rep(i, n) cin >> C[i];
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  dfs(0, -1, 0);
  init(n);
  vector<ll> res(EularTour_V.size());
  rep(i, n){
    res[in[i]] = C[i];
  }
  segtree<ll, op, e> seg(res);
  rep(i, q){
    int t;
    cin >> t;
    int a;
    ll b;
    cin >> a >> b;
    a--;
    if(t == 1){
      ll c = seg.get(in[a]);
      seg.set(in[a], c ^ b);
    }else{
      cout << seg.prod(in[a], out[a]) << endl;
    }
  }
}