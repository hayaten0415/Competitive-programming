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
  for(ll i = 10; i<= 10000; i++){
    ll tmp = i;
    ll num = 0;
    ll cn = 0;
    while(tmp > 0){
      ll plus = tmp % 10;
      num += mypow(i, cn)* plus;
      cn++;
      tmp /= 10;
    }
    if(num == a){
      cout << i << endl;
      return 0;
    }else if(num > a)break;
  }
  cout << -1 << endl;
}
