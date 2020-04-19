#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
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
  return a * b / gcd(a, b);
}

int main() {
  ll a, b, n;
  cin >> a >> b >> n;
  ll num = lcm(a, b);
  if(n % num == 0){
    cout << n << endl;
  }else {
    cout << num * (n / num + 1) << endl;
  }
  return 0;
}