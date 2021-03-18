#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll mod = 1234567;




int main() {
  int n;
  ll p;
  cin >> n >> p;
  vector<ll> dp(n + 1);
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  dp[0] = 1;
  int right = 0;
  ll cost = 0, cnt = 0;
  for (int left = 0; left < n; ++left) {
    while (cost + h[right] <= p && right < n) {
      cost += h[right];
      cnt += dp[right];
      cnt %= mod;
      right++;
      dp[right] = cnt;
    }
    if (right == left) ++right;
    cost -= h[left];
    cnt -= dp[left];
    if(cnt < 0)cnt += mod;
    cnt %= mod;
  }
  cout << dp[n] << endl;
}