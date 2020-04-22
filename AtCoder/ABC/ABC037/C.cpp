#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<ll> a(n + 1, 0);
  for (int i = 0; i < n; i++){
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  for (int j = k; j < n + 1; j++){
    ans += a[j] - a[j - k];
  }
  cout << ans << endl;
}