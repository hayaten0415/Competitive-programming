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
const int INF = (1 << 30);

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<vector<P>> dp(n + 1, vector<P>(2));
  dp[0][0] = {0, INF};
  dp[0][1] = {0, -INF};
  rep(i, n){
    if(dp[i][1].second < A[i]){
      dp[i + 1][0] = max(P(dp[i][1].first + 1, A[i]), dp[i][0]);
    }else{
      chmax(dp[i + 1][0], dp[i][0]);
    }
    if(dp[i][0].second > A[i]){
      if(dp[i + 1][1].first < dp[i][0].first + 1){
        dp[i + 1][1] = P(dp[i][0].first + 1, A[i]);
      }
    }
    if(dp[i + 1][1].first < dp[i][1].first){
      dp[i + 1][1] = dp[i][1];
    }else if(dp[i + 1][1].first == dp[i][1].first && dp[i + 1][1].second > dp[i][1].second){
      dp[i + 1][1] = dp[i][1];
    }
  }
  int ans = max(dp[n][0].first, dp[n][1].first);
  if(ans < 3)ans = 0;
  cout << ans << endl;
}