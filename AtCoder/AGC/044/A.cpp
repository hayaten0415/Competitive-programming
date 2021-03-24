#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define i128 __int128_t
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
ll INF = (1LL << 60);
unordered_map<ll, ll> dp;
ll n, a, b, c, d;

ll rec(ll s){
  if(s<= 0)return 0;
  if(s == 1)return d;
  if(dp.find(s) != dp.end())return dp[s];
  ll res = (s < 3e18 / d ? d * s : LONG_LONG_MAX);
  chmin(res, rec(s / 2) + a + (s % 2) * d);
  chmin(res, rec((s + 1) / 2) + a + (s % 2) * d);
  chmin(res, rec(s / 3) + b + (s % 3) * d);
  chmin(res, rec((s + 2) / 3) + b + (3 - s % 3) * d);
  chmin(res, rec(s  / 5) + c + (s % 5) * d);
  chmin(res, rec((s + 4) / 5) + c + (5 - s % 5) * d);
  return dp[s] = res;
}

void solve() {
  cin >> n >> a >> b >> c >> d;
  cout << rec(n) << endl;
  dp.clear();
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}