#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll ans = (a * b) % mod * c % mod;
  cout << ans << endl;
}