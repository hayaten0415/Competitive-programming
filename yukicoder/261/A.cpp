#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;


ll digitsum(ll n) {
  ll res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll num = n;
  ll ans = 0;
  rep(i, 99) {
    ans = digitsum(num);
    num = ans;
  }
  cout << ans << endl;
}