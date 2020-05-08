#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  rep(i, n) cin >> a[i];
  for(auto x: a){
    mp[x]++;
    mp[x - 1]++;
    mp[x + 1]++;
  }
  int ans = 0;
  for(auto x :mp){
    ans = max(ans, x.second);
  }
  cout << ans << endl;
}