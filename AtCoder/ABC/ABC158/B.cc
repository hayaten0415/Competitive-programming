#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000000;
const int MAX =200000;

int main() {
  ll n, a, b, loop, rest;
  ll ans = 0;
  cin >> n >> a >> b;
  loop = n / (a + b);
  rest = (n % (a + b));
  if(a == 0) {
    cout << 0 << endl;
    return 0;
  }else {
    if(rest < a) {
      ans = a * loop + rest;
    }else {
      ans = a * loop + a;
    }
  }
  cout << ans << endl;
  return 0;
}