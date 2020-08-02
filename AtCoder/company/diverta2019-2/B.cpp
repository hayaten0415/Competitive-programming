#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  map<P, int> mp;
  rep(i, n){
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
  }
  rep(i, n){
    for (int j = i + 1; j < n; j++){
      int x = a[j].first - a[i].first;
      int y = a[j].second - a[i].second;
      mp[{x, y}]++;
      mp[{-x, -y}]++;
    }
  }
  int ans = n;
  int mx = 0;
  for(auto num : mp){
    mx = max(mx, num.second);
  }
  ans -= mx;
  cout << ans << endl;
}