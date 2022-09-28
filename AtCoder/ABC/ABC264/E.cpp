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
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
#define sz(x) ((ll)(x).size())
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void OKNG(bool b = true) { cout << (b ? "OK" : "NG") << '\n'; }
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
  int n, m, e;
  cin >> n >> m >> e;
  UnionFind uf(n + m);
  vector<int> U(e), V(e);
  vector<int> ng(e, false);
  rep(i, e){
    cin >> U[i] >> V[i];
    U[i]--, V[i]--;
  }
  int q;
  cin >> q;
  vector<int> disconnect(q);
  rep(i, q){
    cin >> disconnect[i];
    disconnect[i]--;
    ng[disconnect[i]] = true;
  }
  vector<bool> right(n + m, false);
  rep(i, n, n + m)right[i] = true;
  rep(i, e){
    if(ng[i])continue;
    int a = uf.root(U[i]);
    int b = uf.root(V[i]);
    if(right[a])right[b] = true;
    if(right[b])right[a] = true;
    uf.merge(U[i], V[i]);

  }
  int ans = 0;
  rep(i, n){
    if(right[uf.root(i)])ans++;
  }
  vector<int> res(q);
  rrep(f, q){
    int i = disconnect[f];
    res[f] = ans;
    if(uf.issame(U[i], V[i])){
      continue;
    }
    int a = uf.root(U[i]);
    int b = uf.root(V[i]);
    if(right[a] & !right[b]){
      ans += uf.size(b);
    }
    if(!right[a] & right[b]){
      ans += uf.size(a);
    }
    if(!right[a] & !right[b]){
      uf.merge(U[i], V[i]);
      continue;
    }
    uf.merge(U[i], V[i]);
    right[a] = true;
    right[b] = true;
  }
  for(auto &d :res){
    cout << d << endl;
  }
}