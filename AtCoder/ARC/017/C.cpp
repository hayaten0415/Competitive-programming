#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  int num1 = n / 2;
  int num2 = n - num1;
  ll ans = 0;
  vector<ll> a(num1);
  vector<ll> a_all;
  vector<ll> b(num2);
  map<ll, ll> b_all;
  rep(i, num1) cin >> a[i];
  rep(i,num2) cin >> b[i];
  for (int bit = 0; bit < (1 << num1); bit++){
    ll tmp = 0;
    rep(i,num1){
      if(bit & (1 << i)){
        tmp += a[i];
      }
    }
    a_all.push_back(tmp);
  }
  for (int bit = 0; bit < (1 << num2); bit++){
    ll tmp = 0;
    rep(i,num2){
      if(bit & (1 << i)){
        tmp += b[i];
      }
    }
    b_all[tmp]++;
  }
  rep(i,a_all.size()){
    if(x - a_all[i] < 0)continue;
    ans += b_all[x - a_all[i]];
  }
  cout << ans << endl;
}