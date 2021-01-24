#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


ll op(ll a, ll b) {
  return max(a, b);
}
ll e() {
    return (ll)(0);
}

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n){
    cin >> A[i];
  }
  rep(i, n){
    cin >> B[i];
  }
  segtree<ll, op, e> seg(A);
  ll tmp = 0;
  rep(i, n){
    ll A_mx = seg.prod(0, i + 1);
    ll res = B[i] * A_mx;
    chmax(tmp, res);
    cout << tmp << endl;
  }
}