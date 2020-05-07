#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, n) cin >> a[i];
  vector<ll> sum1(n + 1, 0);
  rep(i,n){
    sum1[i + 1] = sum1[i] + a[i];
  }
  sum = sum1[n];
  ll ans = 1000000000000;
  for (int i = 1; i < n; i++){
    ans = min(ans, abs(sum1[i] - (sum - sum1[i])));
  }
  cout << ans << endl;
}