#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> S(n + 1);
  sort(ALL(A));
  rep(i, n) S[i + 1] = S[i] + A[i];
  auto calc = [&](int x) {
    ll tot = 0, num = 0;
    rep(i, n){
      int j = lower_bound(ALL(A), x - A[i]) - A.begin();
      num += n - j;
      tot += S[n] - S[j];
      tot += A[i] * ll(n - j);
    }
    return make_pair(tot, num);
  };
  int l = 0, r = 200010;
  while (r - l > 1){
    int mid = (l + r) / 2;
    if(calc(mid).second >= m)l = mid;
    else r = mid;
  }
  auto p = calc(l);
  ll ans = p.first;
  ans -= (p.second - m) * l;
  cout << ans << endl;
}