#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  vector<ll> a(n + 1);
  vector<ll> b(n);
  rep(i, n + 1) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }
  rep(i ,n) {
    ll min1 = min(a[i], b[i]);
    a[i] -= min1;
    b[i] -= min1;
    ans += min1;

    ll min2 = min(a[i + 1], b[i]);
    a[i + 1] -= min2;
    b[i] -= min2;
    ans += min2;
  }
  cout << ans << endl;
}