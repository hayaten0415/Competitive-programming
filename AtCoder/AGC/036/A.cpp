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
const ll num = mypow(10,9);
const ll num2 = mypow(10, 17);

int main() {
  ll s;
  cin >> s;
  if(s == mypow(10,18)){
    cout << 0 << " " << 0 << " " << num << " " << 0 << " " << 0 << " " << num << endl;
    return 0;
  }
  if (s <= num){
    cout << 0 << " "<< 0 << " " << s << " " << 0 << " " << 0 << " "<< 1 << endl;
  }else {
    ll sqrt_num = sqrt(s);
    sqrt_num++;
    ll tmp = s - sqrt_num * sqrt_num;
    cout << 0 << " " << 0 << " " << sqrt_num << " " << 1 << " " << abs(tmp) << " " << sqrt_num << endl;
  }
}