#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n){
    cin >> a[i];
    b[i] = a[i] - i - 1;
  }
  sort(b.begin(), b.end());
  ll x = b[n / 2];
  ll ans = 0;
  rep(i,n){
    ans += max(x - b[i], -x + b[i]);
  }
  cout << ans << endl;
}