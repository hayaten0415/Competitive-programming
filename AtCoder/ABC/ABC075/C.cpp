#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
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

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<int> a(m);
  vector<int> b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  rep(i,m){
    UnionFind uf(n);
    rep(j,m){
      if(i == j) continue;
      uf.merge(a[j], b[j]);
    }
    if(uf.size(0) < n) ans++;
  }
  cout << ans << endl;
}