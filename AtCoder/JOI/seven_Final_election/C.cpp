#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  ll m;
  cin >> n >> m;
  n++;
  vector<ll> a(n, 0);
  vector<ll> b;
  ll ans = 0;
  rep(i, n-1) cin >> a[i + 1];
  rep(i, n){
    rep(j, n){
      b.push_back(a[i] + a[j]);
    }
  }
  sort(ALL(b));
  rep(i, n){
    rep(j, n){
      if(m - a[i] - a[j]< 0)continue;
      auto ite = upper_bound(ALL(b), m - a[i] - a[j]);
      if(ite != b.begin())ite--;
      ans = max(ans, a[i] + a[j] + *ite);
    }
  }
  cout << ans << endl;
}