#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;



int main() {
  int x, y, n;
  cin >> x >> y >> n;
  double ans = 1000000000.0;
  vector<pair<double, double>> A(n);
  rep(i,n){
    double x1, y1;
    cin >> x1 >> y1;
    A[i] = {x1, y1};
  }
  A.push_back({A[0].first, A[0].second});
  rep(i,n){
    double a, b, c;
    a = A[i].second - A[i + 1].second;
    b = -A[i].first + A[i + 1].first;
    c = -a * A[i].first - b * A[i].second;
    double d = abs(a * x + b * y + c) / sqrt(a * a + b * b);
    ans = min(ans, d);
  }
  cout << fixed << setprecision(12) << ans << endl;
}