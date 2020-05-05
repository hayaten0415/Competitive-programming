#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int mod = 1000000007;
//素因数分解
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

int main() {
  ll n;
  cin >> n;
  vector<ll> ex(n + 1, 0);
  for (ll i = 2; i <= n; i++){
    const auto &res = prime_factorize(i);
    for(auto p: res) ex[p.first] += p.second;
  }
  ll ans = 1;
  for (int p = 2; p <= n; p++){
    ans *= ex[p] + 1;
    ans %= mod;
  }
  cout << ans << endl;
}