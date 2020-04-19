#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> sum(n + 1);
  sum[0] = 0;
  rep(i, n) {
    cin >> p[i];
    p[i]++;
    sum[i + 1] = sum[i] + p[i];
  }
  int mx = 0;
  for (int i = 0; i + k < n + 1; i++){
    mx = max(mx, sum[i + k]- sum[i]);
  }
  double ans = mx;
  ans /= 2;
  printf("%.10f\n", ans);
  return 0;
}