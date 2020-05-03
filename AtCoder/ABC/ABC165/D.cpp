#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll ans = 0;
  if(b == 1){
    cout << 0 << endl;
    return 0;
  }
  if(b - 1 <= x){
    ans = floor(a * (b - 1) / b);
  }else {
    ans = floor(a * x / b) - a * floor(x / b);
  }
  cout << ans << endl;
}