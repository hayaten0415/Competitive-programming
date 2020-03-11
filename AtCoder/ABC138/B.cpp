#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  double ans = 0;
  cin >> n;
  vector<int> a(n);
  rep(i ,n) {
    cin >> a[i];
  }
  rep(i,n) {
    ans += (double)1 / a[i];
  }
  ans = (double)1 / ans;
  cout << fixed << ans << setprecision(5) << endl;
}