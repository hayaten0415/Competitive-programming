#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll ans = 0;
  ll tmp = 0;
  rep(i, n) cin >> a[i];
  rep(i, n){
    if(a[i] > 0)tmp += a[i];
    else{
      ans += tmp / 2;
      tmp = 0;
    }
  }
  ans += tmp / 2;
  cout << ans << endl;
}