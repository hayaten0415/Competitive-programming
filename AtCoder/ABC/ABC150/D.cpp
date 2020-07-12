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

//最小公倍数を求めるメソッド
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);
  ll lcm_1 = 1;
  ll lcm_2 = 1;
  ll ans = 0;
  bool over = false;
  rep(i, n) cin >> a[i];
  rep(i, n){
    lcm_1 = lcm(lcm_1, a[i]);
    //cout << lcm_1 << endl;
    if(lcm_1 >=m || lcm_1 < 0){
      over = true;
      break;
    }
  }
  rep(i, n){
    lcm_2 = lcm(lcm_2, a[i]/2);
    //cout << lcm_2 << endl;
    if(lcm_2 > m || lcm_2 < 0){
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i, n){
    if(lcm_2 % a[i] != a[i] / 2){
      cout << 0 << endl;
      return 0;
    }
  }
  if(over){
    cout << 1 << endl;
    return 0;
  }
  m += lcm_2;
  ans = m / lcm_1;
  cout << ans << endl;
}