#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++){
    ll k = n / i;
    ans += i * (k * (k + 1) / 2);
  }
  cout << ans << endl;
}
