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
  return 0;
}

int main() {
  int n;
  cin >> n;
  int N = (1 << n);
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  segtree<ll, op, e> seg(A);
  int half = N / 2;
  ll d = seg.prod(0, half);
  ll c = seg.prod(half, N);
  ll k = min(d, c);
  rep(i, N){
    if(A[i] == k){
      cout << i + 1 << endl;
      return 0;
    }
  }
}