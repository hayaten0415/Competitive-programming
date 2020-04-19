#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  int ans = -200000;
  cin >> a >> b;
  ans = max(a + b, a * b);
  ans = max(ans, a - b);
  cout << ans << endl;
}