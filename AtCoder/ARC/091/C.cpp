#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  ans = (ll)(n - 2) * (m - 2);
  if(m == 1) ans = n-2;
  if(n == 1)ans = m-2;
  if(n == 1&& m == 1)ans = 1;
  cout << ans << endl;
}