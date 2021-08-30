#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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
using PP = pair<P, int>;
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

int op(int a, int b){
  return a + b;
}
int e(){
  return 0;
}

int op2(int a, int b){
  return min(a, b);
}
int e2(){
  return 3;
}

bool f(int v){
  return v > 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<PP> LR(m);
  vector<int> A(n, 0);
  segtree<int, op, e> seg(n);
  segtree<int, op2, e2> seg2(A);
  rep(i, m){
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    LR[i].fi.fi = r;
    LR[i].fi.se = l;
    LR[i].se = x;
  }
  sort(ALL(LR));
  vector<int> ans(n);
  for(auto [p, x] : LR){
    auto [r, l] = p;
    if(seg.prod(l, r+1) >= x)continue;
    rep(i, x){
      int left = seg2.min_left<f>(r+1);
      left--;
      ans[left] = 1;
      seg.set(left, 1);
      seg2.set(left, 1);
      if (seg.prod(l, r + 1) >= x)break;
    }
  }
  rep(i, n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}