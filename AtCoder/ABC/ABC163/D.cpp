#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

//繰り返し自乗法(modあり)
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  ll sum = n * (n + 1) / 2;
  for (ll i = k; i <= n +1; i++){
    if(i == 1) {
      ans += n + 1;
      ans %= mod;
    }else if(i == n+1){
      ans += 1;
      ans %= mod;
    }else {
      ll num1 = (i - 1) * i / 2;
      ll num2 = sum - ((n - i) * (n - i + 1) / 2) ;
      ll plus = num2 - num1 + 1;
      ans += plus;
      ans %= mod;
    }
  }
  cout << ans << endl;
}