#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll digitsum(ll n) {
  ll res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, 1);
  for (ll i = 1; i <= n; i++){
    ll digit = digitsum(i);
    if(i + digit > n)continue;
    dp[i + digit] += dp[i];
  }
  cout << dp[n] << endl;
}