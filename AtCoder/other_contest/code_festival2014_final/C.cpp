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
  ll a;
  cin >> a;
  if(a < 10){
    cout << -1 << endl;
    return 0;
  }
  ll left = 9;
  ll right = 10001;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    ll tmp = mid;
    ll num = 0;
    ll cn = 0;
    while(tmp > 0){
      ll plus = tmp % 10;
      num += mypow(mid, cn)* plus;
      cn++;
      tmp /= 10;
    }
    if(num == a){
      cout << mid << endl;
      return 0;
    }else if(num > a){
      right = mid;
    }else {
      left = mid;
    }
  }
  cout << -1 << endl;
}
