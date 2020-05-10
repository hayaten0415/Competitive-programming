#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//繰り返し自乗法(modなし)
ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  int n,m;
  cin >> n >> m;
  int ans = ((n - m) * 100 + m * 1900) * mypow(2, m);
  cout << ans << endl;
}