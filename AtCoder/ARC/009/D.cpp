#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
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
template <typename T>
const auto INF = numeric_limits<T>::max()/2;


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
  bool same(int x, int y) {
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
  void reset(int n){
    par.assign(n,-1);
  }
};

inline int next_combination(int sub){
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}


int main() {
  ll a, t, k, m;
  cin >> a >> t >> k;
  vector<vector<int>> c(a, vector<int>(0));
  vector<bitset<77>> rev(t);
  rep(i,a){
    int ni;
    cin >> ni;
    c[i] = vector<int>(ni);
    rep(j,ni){
      cin >> c[i][j];
      c[i][j]--;
      rev[c[i][j]][i] = true;
    }
  }
  for(auto &ci:c)sort(ALL(ci));
  vector<vector<tuple<int, int, int>>> root(a);
  cin >> m;
  while(m--){
    int ai,bi,ci;
    cin >> ai >> bi >> ci;
    ai--;bi--;
    auto bit = rev[ai] & rev[bi];
    rep(i,77)if(bit[i]){
      ai = lower_bound(ALL(c[i]),ai) - c[i].begin();
      bi = lower_bound(ALL(c[i]), bi) - c[i].begin();
      root[i].eb(ai,bi,ci);
      break;
    }
  }
  ll cnt = 1;
  bool cntflg = false;
  vector w(a, vector(1200, 0LL));

  rep(i,a){
      auto &vi = root[i];
      UnionFind uf(c[i].size());
      int rsz = vi.size(), csz = c[i].size() - 1;
      ll cnt_i = 0;
      for(int bit = (1<<csz)-1; bit < (1<<rsz); bit = next_combination(bit)){
        uf.reset(c[i].size());
        int temp = 0;
        rep(j,rsz){
          auto &[ai,bi,ci] = vi[j];
          if((bit>>j) & 1)uf.merge(ai,bi);
          else temp += ci;
        }
        if(uf.size(uf.root(0)) == csz + 1){
          w[i][temp]++;
          cnt_i ++;
        }
      }
      cnt *= cnt_i;
      if(cnt > k){
        cntflg = true;
      }
    }
    if(!cntflg && cnt < k){
      cout << -1 << endl;
      return 0;
    }
    deque<ll> que;
    rep(i,a)que.emplace_back(i);
    while(que.size() > 1){
      int ind1 = que.front();
      que.pop_front();
      int ind2 = que.front();
      que.pop_front();
      w[ind1] = convolution(w[ind1], w[ind2]);
      ll su = 0;
      rep(i,w[ind1].size()){
        su += w[ind1][i];
        if(su >= k){
          w[ind1][i] -= su - k;
          w[ind1].resize(i+1);
          break;
        }
      }
      if(que.size()==0){
        cout << w[ind1].size() -1 << endl;
        return 0;
      }
      que.emplace_back(ind1);
  }
}