#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  bool cond = true;
  ll sum = 0;
  vector<int> r(n);
  rep(i, n) cin >> r[i];
  sort(r.begin(), r.end());
  for (int i = n - 1; i >= 0; i--){
    if(cond){
      sum += pow(r[i], 2);
      cond = false;
    }else {
      sum -= pow(r[i], 2);
      cond = true;
    }
  }
  double ans = (double)sum * M_PI;
  cout << fixed << ans << setprecision(15) << endl;
  return 0;
}