#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
const long long mod = 2019;
using namespace std;
using ll = long long;

int main() {
  ll L, R;
  ll ans = 2019;
  cin >> L >> R;
  if(R - L >= 2019) {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = L; i < R; i++){
    for (ll j = i + 1; j <= R; j++){
      ans = min(ans, (i  * j)  % mod);
    }
  }
  cout << ans << endl;
}