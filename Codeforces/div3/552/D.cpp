#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;


void solve() {
  int n, a, b;
  cin >> n >> b >> a;
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  vector<vector<P>> dp(n + 1, vector<P>(2, {0, 0}));
  dp[0][0] = {a, b};
  dp[0][1] = {a, b};
  rep(i, n){
    if(dp[i+1][0].first + dp[i+1][0].second < max(dp[i][0].first-1, 0) + dp[i][0].second && dp[i][0].first > 0){
      dp[i + 1][0] = {max(dp[i][0].first - 1, 0), dp[i][0].second};
    }
    if(dp[i+1][0].first + dp[i+1][0].second < max(dp[i][1].first-1, 0) + dp[i][1].second && dp[i][1].first > 0){
      dp[i + 1][0] = {max(dp[i][1].first - 1, 0), dp[i][1].second};
    }
    if(s[i]){
      if(dp[i+1][1].first + dp[i+1][1].second < min(dp[i][0].first+1, a) + max(dp[i][0].second- 1, 0) && dp[i][0].second > 0){
        dp[i + 1][1] = {min(dp[i][0].first + 1, a), max(dp[i][0].second - 1, 0)};
      }
      if(dp[i+1][1].first + dp[i+1][1].second < min(dp[i][1].first+1, a) + max(dp[i][1].second- 1, 0) && dp[i][1].second > 0){
        dp[i + 1][1] = {min(dp[i][1].first + 1, a), max(dp[i][1].second - 1, 0)};
      }
    }else{
      if(dp[i+1][1].first + dp[i+1][1].second < dp[i][0].first + max(dp[i][0].second- 1, 0) && dp[i][0].second > 0){
        dp[i + 1][1] = {dp[i][0].first, max(dp[i][0].second - 1, 0)};
      }
      if(dp[i+1][1].first + dp[i+1][1].second < dp[i][1].first + max(dp[i][1].second- 1, 0) &&  dp[i][1].second > 0){
        dp[i + 1][1] = {dp[i][1].first, max(dp[i][1].second - 1, 0)};
      }
    }
  }
  int ans = 0;
  rep(i, n+1){
    if(dp[i][0].fi + dp[i][0].se > 0)chmax(ans, i);
    if(dp[i][1].fi + dp[i][1].se > 0)chmax(ans, i);
  }
  if(ans < n)ans++;
  cout << ans<< endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}