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
const auto INF = numeric_limits<T>::max()/4;

using S = ll;
using F = ll;
S op(S a, S b){ return max(a, b); }
S e(){ return (-1)*INF<ll>; }
S mapping(F f, S x){ return x+f; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  ll ans = 0;
  int n;
  cin >> n;
  vector<ll> w(n);
  rep(i, n) cin >> w[i];
  vector<tuple<int, int, int>> res;
  rep(i, n){
    int m;
    cin >> m;
    rep(j, m){
      int t;
      cin >> t;
      if(j == 0){
        res.push_back(make_tuple(t / 2, -1, w[i]));
      }else{
        ll pr = get<0>(res[res.size() - 1]);
        res.push_back(make_tuple(t / 2, pr, w[i]));
      }
    }
  }
  sort(ALL(res));
  res.push_back(make_tuple(2e9, 0, 0));
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(500001);
  int j = 0;
  rep(i, 500001){
    ll mx = 0;
    if(i)mx = seg.prod(0LL,i);
    seg.set(i, mx);
    chmax(ans, mx);
    int t = get<0>(res[j]);
    while(t==i){
      int pr = get<1>(res[j]);
      ll v = get<2>(res[j]);
      seg.apply(pr+1,i+1,v);  
      j++;
      t = get<0>(res[j]);
    }
  }
  cout << ans << endl;
}