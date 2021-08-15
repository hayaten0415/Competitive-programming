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
template <typename T>
const auto INF = numeric_limits<T>::max();


int dep[200002];
int in[200002];
int out[200002];
int tree_size[200002];
ll dis[200002];
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
  if(dis[v] == -INF<ll>){
    dis[v] = dist;
  }
  in[v] = k;
  k++;
  dep[v] = d;
  tree_size[v] = 1;
  for (auto [u, cost] : G[v]){
    if(u ==p)continue;
    dfs(u, v, d + 1, (cost ^ dist));
    EularTour_V.pb(v);
    tree_size[v] += tree_size[u];
  }
  out[v] = k;
  EularTour_E.pb(-dist);
  k++;
}

using mint = modint1000000007;
int main() {
  int n;
  cin >> n;
  G.resize(n);
  rep(i, n)dis[i] = -INF<ll>;
  rep(i, n-1){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].pb({b, c});
    G[b].pb({a,c});
  }
  dfs(0, -1, 0, 0);
  mint ans = 0;
  rep(i, 60){
    vector<mint> cn(2);
    rep(j, n){
      cn[dis[j] >> i & 1]++;
    }
    ans += cn[0] * cn[1] * (1LL << i);
  }
  cout << ans.val() << endl;
}