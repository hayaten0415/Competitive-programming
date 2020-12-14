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
  return (a ^ b);
}
ll e() {
    return (ll)(0);
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  segtree<ll, op, e> seg(A);
  vector<ll> ans;
  rep(i, q){
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1){
      x--;
      ll tmp = seg.get(x);
      seg.set(x, tmp ^ y);
    }else{
      x--;
      ans.emplace_back(seg.prod(x, y));
    }
  }
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
}