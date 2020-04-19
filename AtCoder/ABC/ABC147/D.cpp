#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i,60){
    ll x = 0;
    rep(j, n) if (a[j] >> i & 1) x++;
    ll now = x * (n - x) % mod;
    rep(j, i) now = now * 2 % mod;
    ans += now;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}