#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int l;
  cin >> l;
  double length = (double)l / 3;
  double ans = pow(length, 3);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}