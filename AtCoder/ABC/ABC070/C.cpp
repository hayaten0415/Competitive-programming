#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//ユーグリッドの互除法による最大公約数を求めるメソッド
ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

//最小公倍数を求めるメソッド
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  rep(i,n){
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;
}