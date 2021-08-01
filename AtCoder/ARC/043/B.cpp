#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<mint, long long>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);

using S = mint;
using F = mint;
S op(S a, S b) { return a + b; }
S e() { return (mint)0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return (mint)0; }

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  sort(ALL(A));
  vector<mint> dp(n, 0);
  lazy_segtree<S, op, e, mint, mapping, composition, id> tmp(dp);
  vector<lazy_segtree<S, op, e, mint, mapping, composition, id>> seg(4, tmp);
  rep(i, n) seg[0].set(i, 1);
  rep(i, 3){
    rep(j, n){
      ll b = A[j] * 2;
      int c = lower_bound(ALL(A), b) - A.begin();
      if(c == n)continue;
      int left = max(c, j + 1);
      seg[i+1].apply(left, n, seg[i].get(j));
    }
  }
  mint ans = 0;
  rep(i, n){
    ans += seg[3].get(i);
  }
  cout << ans.val() << endl;
}