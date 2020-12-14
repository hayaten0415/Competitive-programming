#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Sieve_prime{
  vector<int> f, primes;
  int n;
  Sieve_prime(int n = 1): n(n), f(n +1){
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; i++){
      if(f[i])continue;
      primes.emplace_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i){
        //この条件をつけると最小素因数が記録される
        //つけないと最大素因数が記録される。
        if(!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorlist(int x){
    vector<int> res;
    while (x != 1){
      res.emplace_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorlist(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}


int main() {
  int L;
  cin >> L;
  L -= 12;
  Sieve_prime Sieve(300);
  if(L == 0){
    cout << 1 << endl;
    return 0;
  }
  int upp = 11 + L;
  int low = L;
  int num = 0;
  map<int, int> mp1, mp2;
  rep(i, L){
    vector<P> tmp1 = Sieve.factor(upp-num);
    vector<P> tmp2 = Sieve.factor(low-num);
    for(auto p: tmp1){
      mp1[p.first] += p.second;
    }
    for(auto p: tmp2){
      mp2[p.first] += p.second;
    }
    num++;
  }
  ll ans = 1;
  rep(i, 230){
    ans *= mypow(i, (ll)mp1[i] - mp2[i]);
  }
  cout << ans << endl;
}