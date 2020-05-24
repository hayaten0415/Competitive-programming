#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll ans = 0;
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  for (ll i = n-1; i >= 0; i--){
    if(a[i] % b[i] != 0){
      ll rest = a[i] % b[i];
      ans += b[i] - rest;
    }
    if(i > 0) a[i-1] += ans;
  }
  cout << ans << endl;
}