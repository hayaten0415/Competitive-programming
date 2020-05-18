#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll all_gcd = a[0];
  rep(i,n){
    all_gcd = gcd(all_gcd, a[i]);
  }
  cout << all_gcd << endl;
}