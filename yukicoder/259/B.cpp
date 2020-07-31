#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const ll MAX_N = 5000000;
ll prime[MAX_N];
bool is_prime[MAX_N + 1];

//エラトステネスの篩
void sieve(ll n){
  ll p = 0;
  n = MAX_N;
  for (ll i = 0; i <= n; i++)is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n; i++){
    if(is_prime[i]){
      prime[p++] = i;
      for (ll j = 2 * i; j <= n; j += i)is_prime[j] = false;
    }
  }
}


ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

void solve() {
  ll a, p;
  cin >> a >> p;
  if(!is_prime[p]){
    cout << -1 << endl;
    return;
  }
  if(gcd(a, p) != 1){
    cout << 0 << endl;
  }else{
    cout << 1 << endl;
  }
  return;
}

int main(){
  sieve(MAX_N);
  int t;
  cin >> t;
  rep(i, t) solve();
}