#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<long long, long long>;
typedef long long ll;

int main() {
  set<P> p;
  int n;
  cin >> n;
  vector<P> A(n);
  ll ans = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    p.insert({x, y});
    A[i] = {x, y};
  }
  sort(ALL(A));
  rep(i, n) {
    for (int j = i + 1; j < n; j++){
      ll x1 = A[i].first, x2 = A[j].first, y1 = A[i].second, y2 = A[j].second;
      ll x = x2 - x1;
      ll y = y2 - y1;
      if (p.find({x1 + y, y1 - x}) != p.end() && p.find({x2 + y, y2 - x}) != p.end()) ans = max(ans, x * x + y * y);
      if (p.find({x1 - y, y1 + x}) != p.end() && p.find({x2 - y, y2 + x}) != p.end()) ans = max(ans, x * x + y * y);
    }
  }
  cout << ans << endl;
}