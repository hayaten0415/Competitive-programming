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


ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0LL; }

int main() {
  int n;
  cin >> n;
  vector<ll> V(n), dp(n);
  vector<int> A(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
  }
  rep(i, n){
    cin >> V[i];
  }
  segtree<ll, op, e> seg(dp);
  rep(i, n){
    ll a = seg.prod(0, A[i]);
    seg.set(A[i], a + V[i]);
  }
  cout << seg.all_prod() << endl;
}