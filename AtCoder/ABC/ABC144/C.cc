#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll n;
  ll a = 0, b = 0;
  ll ans = 100000000000000000;
  cin >> n;
  for (int i = 1; i <= sqrt(n); i++) {
    if(n % i == 0) {
      a = i;
      b = n / a;
      ans = min(a + b - 2, ans);
    }
  }
  cout << ans << endl;
  return 0;
}