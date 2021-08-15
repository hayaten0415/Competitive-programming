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
using Edge = pair<int, long long>; // {行き先, 重み}
using Graph = vector<vector<Edge>>;
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
vector<int> ls[200002];
int k;
Graph G;


//通った頂点を並べたもの
vector<int> EularTour_V;
//通った辺を並べたもの
vector<int> EularTour_E;

void dfs(int v,int p, int d, ll dist) {
  EularTour_V.pb(v);
  EularTour_E.pb(dist);
  in[v] = k;
  k++;
  dep[v] = d;
  tree_size[v] = 1;
  for (auto [u, cost] : G[v]){
    if(u ==p)continue;
    dfs(u, v, d + 1, cost);
    EularTour_V.pb(v);
    tree_size[v] += tree_size[u];
  }
  out[v] = k;
  EularTour_E.pb(-dist);
  k++;
}

//頂点iの部分木クエリは半開区間[in[i], out[i])となる。
//in[i]のみに値を入れる,out[i]には単位元を入れるとセグ木が正しく動く(1点更新のみ)
//1点更新のセグ木のみverify

// verify https://yukicoder.me/problems/no/1637
// verify https://yukicoder.me/problems/no/1641
// verify https://atcoder.jp/contests/abc202/tasks/abc202_e

int main() {
  int n, q;
  cin >> n;
  G.resize(n);
  rep(i, n-1){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].pb({b, c});
    G[b].pb({a,c});
  }
  dfs(0, -1, 0, 0);
  cout << endl;
}