#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double l = (double)6.0 * m;
  double s = (double)30.0 * h + (double)0.5 * m;
  double res = min(abs(l - s), abs(360.0 - (l - s)));
  if(res > 180.0) res = 360.0 - res;
  double ans = (double)pow(a, 2.0) + (double)pow(b, 2.0) - (double)(2 * a * b * cos(res *  M_PI/ 180.0));
  ans = sqrt(ans);
  cout << fixed << setprecision(12) << ans << endl;
}