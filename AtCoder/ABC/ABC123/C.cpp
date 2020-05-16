#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll MAX = 100000000000000000;

int main() {
  ll n;
  cin >> n;
  ll mn = MAX;
  vector<ll> d(5);
  rep(i, 5) {
    cin >> d[i];
    mn = min(mn, d[i]);
  }
  if(mn  >= n ){
    cout << 5 << endl;
    return 0;
  }
  ll ans = n / mn + 4;
  if(n % mn != 0)ans++;
  cout << ans << endl;
}