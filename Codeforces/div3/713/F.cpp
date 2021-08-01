#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

void solve() {
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> A(n), B(n - 1);
  rep(i, n) cin >> A[i];
  rep(i, n-1) cin >> B[i];
  vector<ll> dp(n, INF);
  //firstで移動回数,secondでいくつ余っているか
  vector<PL> dp2(n);
  dp[0] = (c + A[0]-1) / A[0];
  dp2[0] = {((B[0] + A[0] - 1) / A[0]) + 1, ((B[0] + A[0] - 1) / A[0]) * A[0] - B[0]};
  for (int i = 1; i < n; i++){
    if(dp2[i-1].second >= c){
      chmin(dp[i], dp2[i - 1].first);
    }else{
      chmin(dp[i], dp2[i - 1].first + ((A[i] + c - dp2[i - 1].second - 1) / A[i]));
    }
    if(i < n-1){
      if(dp2[i-1].second >=B[i]){
        dp2[i].first = dp2[i - 1].first + 1;
        dp2[i].second = dp2[i - 1].second - B[i];
      }else{
        dp2[i].first = dp2[i - 1].first + ((B[i] - dp2[i - 1].second + A[i] - 1) / A[i]) + 1;
        dp2[i].second = ((B[i] - dp2[i - 1].second + A[i] - 1) / A[i]) * A[i] + dp2[i - 1].second - B[i];
      }
    }
  }
  ll ans = INF;
  rep(i, n){
    chmin(ans, dp[i]);
    //cout << dp2[i].first << " " << dp2[i].second << endl;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}