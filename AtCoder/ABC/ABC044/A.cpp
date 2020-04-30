#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  ll ans = 0;
  rep(i,n){
    if(i >= k){
      ans += y;
    }else {
      ans += x;
    }
  }
  cout << ans << endl;
}