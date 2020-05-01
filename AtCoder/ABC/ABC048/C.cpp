#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n-1){
    ll num1 = a[i];
    ll num2 = a[i + 1];
    if(num1 + num2 > x){
      ll gap = num1 + num2 - x;
      ans += gap;
      if(num2 - gap < 0) {
        num2 = 0;
        num1 -= gap - num2;
      }else {
        num2 -= gap;
      }
    }
    a[i] = num1;
    a[i + 1] = num2;
  }
  cout << ans << endl;
}
