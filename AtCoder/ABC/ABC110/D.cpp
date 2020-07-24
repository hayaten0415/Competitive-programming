#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;
const int MAX = 200000;

vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (long long a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    ll ex = 0; //指数
    while(n % a == 0){
      ex++;
      n /= a;
    }
    res.push_back(make_pair(a, ex));
  }
  if(n != 1){
    res.push_back(make_pair(n, 1));
  }
  return res;
}

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

int main() {
  ll n, m;
  cin >> n >> m;
  COMinit();
  auto vec = prime_factorize(m);
  ll ans = 1;
  for(auto pf : vec){
    int num = pf.second;
    ll tmp = COM(num + n - 1, n - 1);
    ans = (ans * tmp) % MOD;
  }
  cout << ans << endl;
}