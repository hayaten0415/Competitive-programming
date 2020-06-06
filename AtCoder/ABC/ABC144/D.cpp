#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const double PI = acos(-1);

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double s = x / a;
  double rad;
  if(s >= a* b / 2){
    long double h = (a * b - s) * 2 / a;
    rad = atan2(h,a);
  }else{
    long double w = 2 * s / b;
    rad = atan2(b, w);
  }
  double ans = rad / (2 * PI) * 360;
  printf("%.10f\n", ans);
}