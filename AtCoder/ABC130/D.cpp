#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll sum = 0;
  int j = 0;
  ll ans = 0;
  rep(i ,n) {
    while(j < n && sum + a[j] < k){
      sum += a[j];
      j++;
    }
    ans += j - i;
    sum -= a[i];
  }
  ans = (ll)n * (n + 1) / 2 - ans;
  cout << ans << endl;
  return 0;
}