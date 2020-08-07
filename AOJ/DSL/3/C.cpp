#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i,q){
    ll x;
    cin >> x;
    ll ans = 0;
    ll sum = 0;
    int right = 0;
    for (int left = 0; left < n; left++){
      while(right < n &&sum + a[right] <= x){
        sum += a[right];
        right++;
      }
      ans += right - left;
      if(right == left)right++;
      else sum -= a[left];
    }
    cout << ans << endl;
  }
}
