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

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
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


int main() {
  Sieve sieve(1e6);
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int all_gcd = A[0];
  map<int, int> mp;
  rep(i, n){
    auto f = sieve.factor(A[i]);
    for (auto p : f) {
      mp[p.first]++;
    }
    all_gcd = gcd(all_gcd, A[i]);
  }
  int coprime = 1;
  for (auto k : mp){
    if(k.second > 1){
      coprime = 0;
      break;
    }
  }
  
  if(all_gcd != 1){
    cout << "not coprime" << endl;
  }else if(all_gcd == 1 && coprime == 0){
    cout << "setwise coprime" << endl;
  }else{
    cout << "pairwise coprime" << endl;
  }
}