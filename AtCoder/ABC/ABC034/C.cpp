#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

ll fac[200003], inv[200003], finv[200003];

void cominit(int n) {
  int i;
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (i = 2; i < n + 2; i++) {
      fac[i] = fac[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
  }
  return;
}
 
ll com(int n, int r) {
  if (n < r) return 0;
  if (n < 0 || r < 0) return 0;
  return (fac[n] * finv[r]) % mod * finv[n - r] % mod;
}

int main() {
  int h, w;
  int ans = 0;
  cin >> h >> w;
  cominit(h + w);
  ans = com(h + w - 2, w - 1);
  cout << ans << endl;
}
