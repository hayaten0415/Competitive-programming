#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

//ユーグリッドの互除法による最大公約数を求めるメソッド
long gcd(long a, long b) {
  long smaller = min(a, b);
  long bigger = max(a, b);
  long surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

//最小公倍数を求めるメソッド
long lcm(long a, long b) {
  return a * b / gcd(a, b);
}

//素数判定
bool isPrime(int num) {
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
  return 0;
}