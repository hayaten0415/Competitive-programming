#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<long long, long long>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<P> XL(n);
  rep(i, n){
    ll x, l;
    cin >> x >> l;
    XL[i] = {x-l,x +l};
  }
  sort(XL.begin(), XL.end(), [](P a, P b){
    return a.second < b.second;
  });
  ll now = -2000000000000;
  int ans = 0;
  rep(i, n){
    if(now > XL[i].first)continue;
    ans++;
    now = XL[i].second;
  }
  cout << ans << endl;
}