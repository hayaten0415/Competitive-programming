#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, k;
  ll L, R;
  cin >> n >> k >> L >> R;
  ll ans = 0;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll num1 = n / 2, num2 = n - n / 2;
  vector<vector<ll>> a_all(num1 + 1);
  vector<vector<ll>> b_all(num2 + 1);
  for (ll bit = 0; bit < (1 << num1); bit++){
    ll tmp = 0;
    ll tmp_count = __builtin_popcount(bit);
    rep(i,num1){
      if(bit & (1 << i)){
        tmp += a[i];
      }
    }
    a_all[tmp_count].push_back(tmp);
  }
  for (ll bit = 0; bit < (1 << num2); bit++){
    ll tmp = 0;
    ll tmp_count = __builtin_popcount(bit);
    rep(i,num2){
      if(bit & (1 << i)){
        tmp += a[num1 + i];
      }
    }
    b_all[tmp_count].push_back(tmp);
  }
  rep(i, num2 +1){
    sort(b_all[i].begin(), b_all[i].end());
  }
  for (int i = max(0ll, k - num2); i <= num1 && i <= k; i++){
    for(auto v : a_all[i]){
      auto low = lower_bound(b_all[k - i].begin(), b_all[k - i].end(), L - v);
      auto upp = upper_bound(b_all[k - i].begin(), b_all[k - i].end(), R - v);
      if(upp - low <= 0)continue;
      ans += upp - low;
    }
  }
  cout << ans << endl;
}