#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 10000000000000000;
  for (int bit = 0; bit < (1 << n); bit++){
    int mx = 0;
    int ok = 0;
    ll cost = 0;
    vector<int> tmp = a;
    rep(i, n) {
      if(bit & (1 << i)){
        if(tmp[i] > mx){
          mx = tmp[i];
        }else{
          cost += (mx + 1) - a[i];
          mx++;
          tmp[i] = mx;
        }
      }else{
        if(a[i] > mx)mx = a[i];
      }
    }
    mx = 0;
    rep(i, n) {
      if(tmp[i] > mx){
        ok++;
        mx = tmp[i];
      }
    }
    if(ok >= k)ans = min(ans, cost);
  }
  cout << ans << endl;
}