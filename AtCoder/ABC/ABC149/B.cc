#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a = 0, b = 0, k = 0;
  cin >> a >> b >> k;
  if(a <= k){
    k -= a;
    a = 0;
  } else{
    a -= k;
  }
  if(k - a >= 0) b -= k;
  b <= 0 ? b = 0: b = b;
  std::cout << a << " " << b << endl;
}