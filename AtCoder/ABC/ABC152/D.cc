#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

pair<int, int> f(int x) {
  int a = x % 10;
  int b = 0;
  while(x) {
    b = x;
    x /= 10;
  }
  pair<int, int> P;
  P = make_pair(a, b);
  return P;
}

int main() {
  int n;
  cin >> n;
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++){
    pair<int, int> p = f(i);
    mp[p]++;
  }
  ll ans = 0;
  for(int i=1; i<=n; i++){
    pair<int, int> p = f(i);
    pair<int, int> q(p.second, p.first);
    ans += mp[q];
  }
  cout << ans << endl;
  return 0;
}