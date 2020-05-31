#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n+1);
  rep(i, n + 1) cin >> a[i];
  vector<ll> Lower(n + 1);
  vector<ll> Upper(n + 1);
  Lower[n] = Upper[n] = a[n];
  for (int i = n - 1; i >= 0; i--){
    Lower[i] = a[i] + (Lower[i + 1] + 1) / 2;
    Upper[i] = a[i] + Upper[i + 1];
  }
  if(Lower[0] > 1){
    cout << -1 << endl;
    return 0;
  }
  ll cur = 1;
  ll ans = 0;
  rep(i, n+1){
    ans += cur;
    cur -= a[i];
    cur = min(cur * 2, Upper[i + 1]);
  }
  cout << ans << endl;
}