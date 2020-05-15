#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  ll mod0 = n / k;
  if(k == 1){
    ans = mypow(n, 3);
    cout << ans << endl;
    return 0;
  }
  if(k % 2 == 0){
    if(n % k >= k / 2){
      ans = mypow(mod0, 3) + mypow(mod0 + 1, 3);
    }else {
      ans = 2 * mypow(mod0, 3);
    }
    cout << ans << endl;
  }else {
    ans = mypow(mod0, 3);
    cout << ans << endl;
  }
}