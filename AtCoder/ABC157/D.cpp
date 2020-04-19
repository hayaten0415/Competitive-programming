#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

struct UnionFind {
  vector<int> par; //par[i]:iの親の番号

  //最初は全てが根であるとする。-1のときに根である。
  UnionFind(int N) : par(N, -1){}

  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
  int root(int x) {
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  //xとyが同じ集合に属するか
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  void merge(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return;
    if(par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
  }

  int size(int x) {
    return -par[root(x)];
  }
};

int deg[100005];
vector<int> to[100005];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind uf(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    deg[a]++;
    deg[b]++;
    uf.merge(a, b);
  }
  rep(i,k){
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i,n) {
    int ans = uf.size(i) - 1 - deg[i];
    for(int u : to[i]) {
      if(uf.issame(i,u)) ans--;
    }
    printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
