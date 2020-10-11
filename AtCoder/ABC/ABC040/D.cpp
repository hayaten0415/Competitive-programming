#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int, int>> q;
  rep(i,M){
    int a, b, y;
    cin >> a >> b >> y;
    a--, b--;
    q.emplace_back(make_tuple(y, 1, a, b));
  }
  int Q;
  cin >> Q;
  rep(i, Q){
    int v, w;
    cin >> v >> w;
    v--;
    q.push_back(make_tuple(w, 2, v, i));
  }
  sort(q.rbegin(), q.rend());
  vector<int> ans(Q);
  UnionFind UF(N);
  rep(i, M+Q){
    int t = get<1>(q[i]);
    if (t == 1){
      int a = get<2>(q[i]);
      int b = get<3>(q[i]);
      if (!UF.issame(a, b)){
        UF.merge(a, b);
      }
    }
    if (t == 2){
      int v = get<2>(q[i]);
      int id = get<3>(q[i]);
      ans[id] = UF.size(v);
    }
  }
  for (int i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }
}