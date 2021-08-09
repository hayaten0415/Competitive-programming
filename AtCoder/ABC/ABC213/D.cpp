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
Graph G;


int dep[200002];
int in[200002];
int out[200002];
int tree_size[200002];
vector<int> ls[200002];
int k;


//通った頂点を並べたもの
vector<int> EularTour_V;
//通った辺を並べたもの
vector<int> EularTour_E;

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
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  rep(i, n) sort(ALL(G[i]));
  dfs(0, -1, 0);
  for(auto s: EularTour_V){
    cout << s + 1 << " ";
  }
  cout << endl;
}