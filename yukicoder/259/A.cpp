#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, d;
  cin >> n >> d;
  vector<ll> x(n), v(n);
  rep(i, n) cin >> x[i];
  ll sum = 0;
  rep(i, n){
    cin >> v[i];
    sum += v[i];
  }
  ll ans = (sum + d - 1) / sum;
  cout << ans << endl;
}