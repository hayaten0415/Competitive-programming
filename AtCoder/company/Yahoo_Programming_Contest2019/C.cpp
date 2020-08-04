#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  if(b-a <= 2 || k < a-1){
    cout << k + 1 << endl;
    return 0;
  }
  k -= a - 1;
  ll ans = a;
  if(k % 2 == 1)ans++, k--;
  ans += (b - a) * (k / 2);
  cout << ans << endl;
}