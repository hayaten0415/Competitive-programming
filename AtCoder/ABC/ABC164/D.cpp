#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
  string s;
  cin >> s;
  vector<ll> d(s.size() + 1);
  int ten = 1;
  for (int i = s.size()-1; i >= 0; --i) {
    int a = (s[i]-'0') * ten % mod;
    d[i] = (d[i+1]+a) % mod;
    ten *= 10; ten %= mod;
  }
  vector<ll> cnt(s.size() + 1);
  ll ans = 0;
  for (int i = s.size(); i >= 0; --i) {
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }
  cout << ans << endl;
  return 0;
}
