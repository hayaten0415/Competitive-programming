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
const ll INF = (1LL <<60);

ll op(ll a, ll b) {
  return (a ^ b);
}
ll e() {
  return (ll)(0);
}

int dep[200002];
int in[200002];
int out[200002];
int tree_size[200002];
int k;
Graph G;

//通った頂点を並べたもの
vector<int> EularTour_V;
//通った辺を並べたもの
vector<int> EularTour_E;

void dfs(int v,int p, int d) {
  EularTour_V.pb(v);
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
  k++;
}

//頂点iの部分木クエリは半開区間[in[i], out[i])となる。
//in[i]のみに値を入れる,out[i]には単位元を入れるとセグ木が正しく動く

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