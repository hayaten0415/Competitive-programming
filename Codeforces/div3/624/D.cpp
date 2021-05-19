#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


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

Sieve_prime Sieve(2e5 + 1);

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans_a = 0, ans_b = 0, ans_c = 0;
  ll ans = (1LL << 60);
  for (int i = 1; i <= 20000; i++){
    vector<int> div = Sieve.divisors(i);
    ll res = (ll)abs(i - b);
    int tmp_a = -1;
    int f = lower_bound(ALL(div), a) - div.begin();
    if(f > 0 && f != (int)div.size()){
      if(abs(div[f] -a) > abs(div[f-1] - a)){
        res += (ll)abs(div[f - 1] - a);
        tmp_a = div[f-1];
      }else{
        res += (ll)abs(div[f] - a);
        tmp_a = div[f];
      }
    }else if(f == 0){
      res += (ll)abs(div[f] - a);
      tmp_a = div[f];
    }else if(f == (int)div.size()){
      res += (ll)abs(div[f-1] - a);
      tmp_a = div[f-1];
    }
    int s = c / i;
    int k = s + 1;
    if(abs((i * s) - c) < abs((i * k) -c)){
      res += (ll)abs((i * s) - c);
      if(chmin(ans, res)){
        ans_a = tmp_a;
        ans_b = i;
        ans_c = i * s;
      }
    }else{
      res += (ll)abs((i * k) - c);
      if(chmin(ans, res)){
        ans_a = tmp_a;
        ans_b = i;
        ans_c = i * k;
      }
    }
  }
  cout << ans << endl;
  cout << ans_a << " " << ans_b << " " << ans_c << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}