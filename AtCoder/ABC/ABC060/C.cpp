#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, t;
  cin >> n >> t;
  ll limit = t;
  ll ans = t;
  vector<ll> time(n);
  rep(i, n) cin >> time[i];
  rep(i,n){
    if(i > 0){
      if(time[i] >=limit){
        ans += t;
      }else {
        ans += time[i] - time[i-1];
      }
      limit = time[i] + t;
    }
  }
  cout << ans << endl;
}