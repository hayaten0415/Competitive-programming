#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 998244353;
const int MAX = 2000000;

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

ll COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  if(n > m){
    cout << 1 << endl;
    return 0;
  }
  if(n ==1){
    cout << 1 << endl;
    return 0;
  }
  COMinit();
  for (int j = 1; m - j * n >= 0; j++){
    ans += COM(m - n * j + j, j);
    ans %= MOD;
  }
  ans++;
  ans %= MOD;
  cout << ans << endl;
}