#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  sort(a.begin(), a.end(), greater<ll>());
  ans += a[0];
  int cn = 0;
  int j = 1;
  rep(i, n-2){
    ans += a[j];
    cn++;
    if(cn == 2){
      cn = 0;
      j++;
    }
  }
  cout << ans << endl;
}