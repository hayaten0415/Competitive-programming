#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll calc(ll n) {
  if(n <= 0) return 0;
  if(n % 4 == 0) {
    return n;
  }else if(n % 4 == 1) {
    return 1;
  }else if(n % 4 == 2) {
    return 1 ^ n;
  }else {
    return 0;
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (calc(b) ^ calc(a - 1)) << endl;
}