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
using ld = long double;

template <typename T>
vector<T> compress(vector<T> &X) {
  // ソートした結果を vals に
  vector<T> vals = X;
  sort(vals.begin(), vals.end());
  // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  // 各要素ごとに二分探索で位置を求める
  for (int i = 0; i < (int)X.size(); i++) {
    X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
  }
  return vals;
}


pair<ld,ld>op(pair<ld,ld>a,pair<ld,ld>b){
  return {a.first*b.first,b.first*a.second+b.second};
}
pair<ld,ld>e(){
  return {(ld)1,(ld)0};
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ld> p(m), a(m), b(m);
  rep(i,m) cin >> p[i] >> a[i] >> b[i];
  ll N = 100100;
  segtree<pair<ld, ld>, op, e> seg(N);
  compress(p);
  ld mx = 1;
  ld mn = 1;
  rep(t,m){
    seg.set(p[t],{a[t],b[t]});
    auto ans = seg.all_prod();
    ld res = ans.first+ans.second;
    chmin(mn,res);
    chmax(mx,res);
  }
  cout << fixed << setprecision(10);
  cout << mn << endl;
  cout << mx << endl;
}