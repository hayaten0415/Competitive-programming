#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PP = pair<int, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using S = int;
using F = int;
S op(S a, S b) { return std::min(a, b); }
S e() { return int(1e9) + 1; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
F id() { return int(1e9) + 1;}

int main() {
  int n, q;
  cin >> n >> q;
  vector<PP> A(n);
  rep(i, n){
    cin >> A[i].second.first >> A[i].second.second >> A[i].first;
  }
  sort(ALL(A));
  vector<int> D(q), ans(q, int(1e9) + 1);
  rep(i, q){
    cin >> D[i];
  }
  lazy_segtree<S, op, e, int, mapping, composition, id> seg(ans);
  rep(i, n){
    int left_limit = max(A[i].second.first - A[i].first, 0);
    int right_limit = A[i].second.second - A[i].first;
    if(left_limit >= right_limit)continue;
    int left = lower_bound(ALL(D), left_limit) - D.begin();
    int right = lower_bound(ALL(D), right_limit) - D.begin();
    seg.apply(left, right, A[i].first);
  }
  rep(i, q){
    int d = seg.get(i);
    if(d == int(1e9) + 1)d = -1;
    cout << d << endl;
  }
}