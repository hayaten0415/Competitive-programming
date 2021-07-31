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
vector<vector<int>> G, parent;
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

int main(){
  int n, m;
  cin >> n >> m;
  G.resize(n);
  depth.resize(n);
  parent.resize(21, vector<int>(n));
  rep(i, n - 1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  init(n);
  rep(i, m){
    int k;
    cin >> k;
    vector<int> vertex(k);
    int c = 0;
    rep(i, k){
      cin >> vertex[i];
      vertex[i]--;
      if(depth[c] < depth[vertex[i]]){
        c = vertex[i];
      }
    }
    bool ok = true;
    rep(i, k){
      int d = lca(c, vertex[i]);
      int dist = depth[d] + depth[vertex[i]] - 2 * depth[d];
      if(dist > 1){
        ok = false;
        break;
      }
    }
    if(!ok){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
}