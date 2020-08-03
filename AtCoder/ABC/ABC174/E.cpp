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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  int l = 0, r = 1e9;
  while (r - l > 1){
    int x = (l + r) / 2;
    auto ok = [&](int x) {
      ll num = 0;
      rep(i, n) num += (a[i] - 1) / x;
      return num <= k;
    };
    if(ok(x)) r = x;
    else l = x;
  }
  cout << r << endl;
}