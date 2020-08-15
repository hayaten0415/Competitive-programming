#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  // データxが根かどうか
  bool cond_root(int x){
    if(par[x] < 0) return true;
    else return false;
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
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> x(n);
  vector<int> imos(n);
  rep(i, n) cin >> x[i];
  UnionFind uf(n);
  rep(i, n) {
    int l = lower_bound(ALL(x), x[i] + a) - x.begin();
    int r = upper_bound(ALL(x), x[i] + b) - x.begin() - 1;
    if(l>r)continue;
    uf.merge(i, l);
    imos[l]++;
    imos[r]--;
  }
  rep(i, n - 1) imos[i + 1] += imos[i];
  rep(i, n - 1) {
    if(imos[i] > 0)uf.merge(i, i+1);
  }
  rep(i, n) {
    cout << uf.size(i) << endl;
  }
}