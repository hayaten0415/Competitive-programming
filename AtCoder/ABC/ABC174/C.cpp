#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int k;
  cin >> k;
  if(k % 2 == 0){
    cout << -1 << endl;
    return 0;
  }
  if(k % 5 == 0){
    cout << -1 << endl;
    return 0;
  }
  if(k == 7){
    cout << 1 << endl;
    return 0;
  }
  int ans = 1;
  ll kakeru = 1;
  rep(i, k){
    ll num = 7 * kakeru;
    if(num % k == 0){
      cout << ans << endl;
      return 0;
    }
    kakeru *= 10;
    kakeru += 1;
    kakeru %= k;
    ans++;
  }
  cout << ans << endl;
}