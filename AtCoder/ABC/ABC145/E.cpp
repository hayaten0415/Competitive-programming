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
int dp[3001][6001];

int main() {
  int n, t;
  cin >> n >> t;
  vector<P> AB;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    AB.push_back({a, b});
  }
  sort(ALL(AB));
  int ans = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= t - 1; j++){
      dp[i][j] = dp[i - 1][j];
      ans = max(ans, dp[i][j] + AB[i - 1].second);
      if(j - AB[i-1].first >= 0){
        dp[i][j] = max(dp[i][j], dp[i - 1][j - AB[i-1].first] + AB[i - 1].second);
      }
    }
  }
  cout << ans << endl;
}