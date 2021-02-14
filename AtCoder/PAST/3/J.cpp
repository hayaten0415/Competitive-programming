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
  return min(a, b);
}
ll e() {
    return (ll)(100000000000000000);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> A(m), child(n, 0);
  rep(i, m) cin >> A[i];
  segtree<ll, op, e> seg(child);
  vector<ll> ans;
  rep(i, m){
    int left = 0;
    int right = n;
    if(seg.all_prod() >= A[i]){
      cout << -1 << endl;
      continue;
    }
    while (right - left > 1){
      int mid = (left + right) / 2;
      if(seg.prod(left, mid) < A[i]){
        right = mid;
      }else{
        left = mid;
      }
    }
    cout << right << endl;
    seg.set(left, A[i]);
  }
}