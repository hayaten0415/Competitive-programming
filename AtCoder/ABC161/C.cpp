#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  if(n < k){
    ll num = abs(n - k);
    cout << min(num, abs(num - k)) << endl;
    return 0;
  }else {
    ll num2 = n % k;
    cout << min(num2, abs(num2 - k)) << endl;
    return 0;
  }
}