//プログラミングコンテストチャレンジブック第二版
//293p-294p

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
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
  int n;
  cin >> n;
  G.resize(n);
  depth.resize(n);
  parent.resize(21, vector<int>(n));
  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  init(n);
}