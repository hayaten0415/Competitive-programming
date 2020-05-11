#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 998244353;
const int MAX = 300000;

ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
// n= 200000までのやつ
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
ll COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  COMinit();
  ll ans = 0;
  for (ll i = 0; i <= k; i++){
    ll num =  m  * modpow(m - 1, n - 1 - i, MOD) % MOD;
    num *= COM(n - 1, i) % MOD;
    ans += num;
    ans %= MOD;
  }
  cout << ans << endl;
}