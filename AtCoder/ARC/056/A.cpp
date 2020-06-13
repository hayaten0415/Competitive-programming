#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b, k, l;
  cin >> a >> b >> k >> l;
  ll l_num = k / l;
  ll ans = l_num * b;
  ans += (k - l_num * l) * a;
  l_num++;
  ans = min(ans, l_num * b);
  cout << ans << endl;
}