#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, P>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max();

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


void solve() {
  int n, m;
  cin >> n >> m;
  vector<PL> edge(n - 1);
  vector<P> q(m);
  vector<ll> ans(m, 0);
  rep(i, n-1){
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    edge[i].second.first--;
    edge[i].second.second--;
  }
  rep(i, m){
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(ALL(edge));
  sort(ALL(q));
  UnionFind uf(n);
  int cond = 0;
  ll pre = 0;
  if(n == 1){
    rep(i, m){
      cout << ans[i] << (i == m - 1 ? "\n" : " ");
    }
    return;
  }
  rep(i, m){
    ll tmp = pre;
    while(q[i].first >=edge[cond].first && cond < n-1){
      tmp += (ll)uf.size(edge[cond].second.first) * (ll)uf.size(edge[cond].second.second);
      uf.merge(edge[cond].second.first, edge[cond].second.second);
      cond++;
    }
    ans[q[i].second] = tmp;
    pre = tmp;
  }
  rep(i, m){
    cout << ans[i] << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}