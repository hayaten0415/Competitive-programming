#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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


int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<pair<ll, ll>> res = prime_factorize(n);
  rep(i, res.size()){
    ll j = 1;
    ll num = res[i].second;
    while(num  - j >= 0){
      ans++;
      num -= j;
      j++;
    }
  }
  cout << ans << endl;
}