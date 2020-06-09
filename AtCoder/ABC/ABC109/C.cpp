#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  if(smaller == 0) return bigger;
  surplus = gcd(smaller, surplus);
  return surplus;
}

int main() {
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> x(N+1);
  rep(i, N) cin >> x[i];
  x[N] = X;
  sort(x.begin(), x.end());
  ll ans = x[1] - x[0];
  for (int i = 1; i < N; i++){
    ans = gcd(ans, x[i + 1] - x[i]);
  }
  cout << ans << endl;
}