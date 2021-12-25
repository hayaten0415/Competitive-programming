#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> sum(n + 1, 0);
  rep(i,n) {
    ll num = 0;
    cin >> num;
    sum[i + 1] = sum[i] + num;
  }
  map<ll, ll> cnt;
  ll ans = 0;
  rep(i, n + 1){
    ans += cnt[sum[i] - k];
    cnt[sum[i]]++;
  }
  cout << ans << endl;
}