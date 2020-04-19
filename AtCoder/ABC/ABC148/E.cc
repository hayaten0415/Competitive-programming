#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll g1 (ll n, int p) {
  if(n == 0) return 0;
  return n / p + g1(n / p, p);
}

ll g2(ll n, int p) {
  ll res = g1(n / 2, p);
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  if(n % 2 == 0) {
    ans = g2(n, 5);
  }
  cout << ans << endl;
}