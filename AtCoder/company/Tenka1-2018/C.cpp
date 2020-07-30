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
  vector<ll> a(n), res(n);
  ll ans1 = 0;
  ll ans2 = 0;
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  res[0] = -1;
  if(n % 2 == 0)res[n-1] = 1;
  else res[n-1] = -1;
  int plus = 1;
  for (int i = 1; i < n - 1; i++){
    if(plus)res[i] = 2;
    else res[i] = -2;
    plus = plus ^ 1;
  }
  sort(ALL(res));
  rep(i, n){
    ans1 += a[i] * res[i];
  }
  rep(i, n){
    ans2 += -1 * a[i] * res[n - 1 - i];
  }
  cout << max(ans1, ans2) << endl;
}