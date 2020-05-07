#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int MOD = 1000000007;
const int MAX = 200000;

ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
// n= 200000までのやつ
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  COMinit();
  if(abs(m - n) > 1){
    cout << 0 << endl;
    return 0;
  }
  ll ans = fac[n] * fac[m] % MOD;
  if(m == n) ans *= 2; ans %= MOD;
  cout << ans << endl;
}