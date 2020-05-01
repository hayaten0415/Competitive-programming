#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  if(a == 0) {
    cout << b / x + 1 << endl;
    return 0;
  }
  ll ans = b / x - (a - 1) / x;
  cout << ans << endl;
}
