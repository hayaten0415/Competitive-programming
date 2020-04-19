#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  n %= 12;
  double l = (double)6.0 * m;
  double s = (double)30.0 * n + (double)0.5 * m;
  double ans = min(abs(l - s), abs(360 - (l - s)));
  if(ans > 180.0) ans = 360 - ans;
  cout << fixed << ans << setprecision(4) << endl;
}