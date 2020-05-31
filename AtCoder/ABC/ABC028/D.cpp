#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans_case = 6 * (k - 1) * (n - k) + 3 * (n - k) + 3 * (k - 1) + 1;
  double ans = (double)ans_case / (double)pow(n, 3);
  cout << fixed << setprecision(12) << ans << endl;
}