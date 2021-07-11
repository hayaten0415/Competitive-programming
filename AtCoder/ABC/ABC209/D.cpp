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
Graph G, parent;
vector<int> depth;
int root = 0;

void dfs(int v, int p, int d){
  parent[0][v] = p;
  depth[v] = d;
  for(auto i : G[v]){
    if(i != p){
      dfs(i, v, d+1);
    }
  }
}

void init(int N){
  //parent[0]とdepthを初期化
  dfs(root, -1, 0);
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
  if(depth[u] > depth[v])swap(u, v);
  for(int k = 0; k < 21; k++){
    if((depth[v] - depth[u]) >> k & 1){
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

int main() {
  int n, q;
  cin >> n >> q;
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  depth.resize(n);
  parent.resize(21, vector<int>(n));
  init(n);
  rep(i, q){
    int a, b;
    cin >> a >> b;
    a--; b--;
    int s = lca(a, b);
    int ans = depth[a] + depth[b] - 2 * depth[s];
    if(ans %2 == 0){
      cout << "Town" << endl;
    }else{
      cout << "Road" << endl;
    }
  }
}