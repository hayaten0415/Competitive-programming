#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int MAX = 200000;

ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
// n= 200000までのやつ
void COMinit()
{
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

// 二項係数計算
ll COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  COMinit();
  rep(i, n) cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  ll f_min = 0;
  ll f_max = 0;
  rep(i,n){
    f_min += A[i] * COM(n - i - 1, k - 1);
    f_min %= MOD;
  }
  for (int i = n - 1; i >= 0; i--){
    f_max += A[i] * COM(i, k - 1);
    f_max %= MOD;
  }
  cout << (f_max - f_min + 2 * MOD) % MOD << endl;
}