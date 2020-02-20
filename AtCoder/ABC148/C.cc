#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

long gcd(long a, long b) {
  long smaller = min(a, b);
  long bigger = max(a, b);
  long surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

long lcm(long a, long b) {
  return a * b / gcd(a, b);
}

int main() {
  long a, b;
  long ans = 0;
  cin >> a >> b;
  ans = lcm(a, b);
  cout << ans << endl;
  return 0;
}