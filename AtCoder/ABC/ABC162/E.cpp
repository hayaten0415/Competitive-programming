#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


const ll MOD = 1000000007;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
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
  ll n, k;
  cin >> n >> k;
  vector<ll> dp(k + 1, 0);
  ll ans = 0;
  for (ll i = k; i > 0; i--){
    ll num = k / i;
    ll tmp = modpow(num, n, MOD);
    dp[i] = tmp;
    ll i_i = i * 2;
    while(i_i <= k){
      dp[i] -= dp[i_i];
      i_i += i;
    }
  }
  for (ll i = 1; i <= k; i++){
    ans += dp[i] * i % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}