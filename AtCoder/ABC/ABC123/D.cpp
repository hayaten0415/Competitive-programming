#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z), d,ans;
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(ALL(c),greater<ll>());
  rep(i, x) {
    rep(j, y) {
      d.emplace_back(a[i] + b[j]);
    }
  }
  sort(ALL(d),greater<ll>());
  rep(i, min(k, x * y)) {
    rep(j, min(z, k)) {
      ans.emplace_back(d[i] + c[j]);
    }
  }
  sort(ALL(ans), greater<ll>());
  rep(i, k) {
    printf("%lld",ans[i]);
    printf("\n");
  }
}