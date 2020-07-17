#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll digitsum(ll n) {
  ll res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  int cnt = 0;
  vector<ll> ans;
  for (ll i = n - 153; i <= n; i++){
    if(i <= 0)continue;
    ll tmp = i;
    tmp += digitsum(i);
    if(tmp == n){
      ans.push_back(i);
      cnt++;
    }
  }
  cout << cnt << endl;
  rep(i, cnt){
    cout << ans[i] << endl;
  }
}