#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


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
  return a * b / gcd(a, b);
}


int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll lc = lcm(c, d);
  ll num1 = a - 1;
  ll num1_c = num1 - ((num1 / c) + (num1 / d) - (num1 / lc));
  ll all = b - ((b / c) + (b / d) - (b / lc));
  cout << all - num1_c << endl;
  return 0;
}