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
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using S = int;
using F = int;
S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }
S mapping(F f, S x) { return max(f, x); }
F composition(F f, F g) { return max(f, g); }
F id() { return 0; }

int main() {
  int w, n;
  cin >> w >> n;
  vector<int> res(w + 1);
  vector<int> ans;
  azy_segtree<S, op, e, int, mapping, composition, id> seg(imos);
  rep(i, n){
    int left, right;
    cin >> left >> right;
    left--;
    int mx = seg.prod(left, right);
    ans.pb(mx + 1);
    seg.apply(left, right, mx + 1);
  }
  rep(i, n) cout << ans[i] << endl;
}