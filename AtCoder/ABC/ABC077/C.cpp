#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  rep(i,n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  for (ll i = 0; i < n; i++){
    ll key = b[i];
    //aの中でkey未満を探す
    auto iter_lower = lower_bound(a.begin(), a.end(), key);
    ll idx_lower_a = distance(a.begin(), iter_lower);
    ll num_a = (iter_lower == a.end()) ? n :idx_lower_a;
    //cの中でkeyより大きいものを探す
    auto iter_upper = upper_bound(c.begin(), c.end(), key);
    ll idx_bound_c = distance(c.begin(), iter_upper);
    ll num_c = (iter_upper == c.end()) ? 0 : n - idx_bound_c;
    ans += num_a * num_c;
  }
  cout << ans << endl;
}