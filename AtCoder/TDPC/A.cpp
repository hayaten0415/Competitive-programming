#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int INF = 100000000;
bool dp[101][10001];

int main() {
  dp[0][0] = true;
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  rep(j, n){
    rep(i, 10001){
      if(i + p[j] < 10001 & dp[j][i]){
        dp[j + 1][i + p[j]] = true;
        dp[j + 1][i] = true;
      }
    }
  }
  int ans = 0;
  rep(i, 10001){
    if(dp[n][i])ans++;
  }
  cout << ans << endl;
}