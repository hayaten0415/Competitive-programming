#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (p == 2 || p == 5){
    ll ans = 0;
    rep(i,n){
      if((s[i] - '0') % p == 0){
        ans += i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }
  vector<int> d(n + 1);
  int ten = 1;
  for (int i = n - 1; i >= 0; i--){
    int a = (s[i] - '0') * ten % p;
    d[i] = (d[i + 1] + a) % p;
    ten *= 10; ten %= p;
  }
  vector<int> cnt(p);
  ll ans = 0;
  for (int i = n; i >= 0; i--) {
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }
  cout << ans << endl;
  return 0;
}