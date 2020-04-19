#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;

int main() {
  int a, b;
  int ans = -1;
  double num1, num2;
  cin >> a >> b;
  for (int i = 1; i <= 1000; i++) {
    num1 = (double)i * 8 / 100;
    num2 = (double)i * 10 / 100;
    if((double)a <= num1 && num1 < (double)a + 1 && (double)b <= num2 && num2 < (double)b + 1) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}