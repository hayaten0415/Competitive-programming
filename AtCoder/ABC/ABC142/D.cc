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

//素数判定
bool isPrime(ll num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) {
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll n = gcd(a, b);
  ll ans = 1;
  for(int i = 2; i <= sqrt(n); ++i){
    if(n%i != 0) continue;
    while(n%i == 0) n /= i;
    ++ans;
  }
  if(n > 1) ans++;
  cout << ans << endl;
  return 0;
}