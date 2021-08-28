#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;


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
  vector<int> divisors(int x){
    assert(x > 0);
    vector<int> res = {1};
    for(auto [p, e] : factor(x)){
      int n = res.size() * e;
      for(int i=0; i<n; ++i){
        res.push_back(res[i] * p);
      }
    }
    sort(ALL(res));
    return res;
  }
};

Sieve_prime Sieve(20000000 + 2);



int main() {
  ll l, r;
  cin >> l >> r;
  deque<ll> q;
  ll ans = 0;
  ll sum = 0;
  for (ll i = l; i <= r * 2; i++){
    if(Sieve.isPrime(i)){
      if(l <= i && i <= r)ans++;
      if(i == 2)continue;
      ll c = i / 2;
      if(l <= c && c + 1 <= r)ans++;
    }
  }
  cout << ans << endl;
}