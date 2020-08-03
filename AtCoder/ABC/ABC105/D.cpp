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
  vector<ll> a(n);
  ll ans = 0;
  map<ll,int> cnt;
  rep(i, n){
    cin >> a[i];
    a[i] %= m;
  }
  rep(i, n-1){
    a[i + 1] = (a[i] + a[i + 1]) % m;
  }
  rep(i, n){
    ans += cnt[a[i]];
    cnt[a[i]]++;
    if(a[i] == 0)ans++;
  }
  cout << ans << endl;
}